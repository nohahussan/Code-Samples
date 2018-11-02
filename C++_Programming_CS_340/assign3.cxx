#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <memory>

using namespace std;

class ship
{
  public:
    // All ships must have a name so prohibit the default constructor...
    ship() = delete;

    // Prohibit copies...
    ship(const ship&) = delete;
    ship& operator = (const ship&) = delete;

    // Permit moves...
    ship(ship&& s):name_(move(s.name_)){}
    ship& operator = (ship&& s){
      do_ship_only_move(move(s));
      return *this;
    }

    virtual ~ship(){};

    // Permit specifying a name...
    explicit ship(string const& name):name_(name){}
    explicit ship(string&& name):name_(move(name)){}

    virtual void sail() = 0;

    virtual string get_ship_type() const{
      return string("ship");
    }

    string const& get_name() const{
      return name_;
    }
    string get_type_name_addr() const{
      ostringstream buf;
      buf << get_ship_type() << ' ' << get_name() << " [" << this << ']';
      return buf.str();
    }

    protected:
      void do_ship_only_move(ship&& s){
        if (this != &s){
          name_ = move(s.name_);
        }
      }

    private:
      string name_;
};

class battle_ship : public virtual ship
{
  public:
    // All ships must have a name so prohibit the default constructor...
    battle_ship() = delete;

    // Prohibit copies...
    battle_ship(const battle_ship&) = delete;
    battle_ship& operator = (const battle_ship&) = delete;

    // Permit moves...
    battle_ship(battle_ship&& s):ship(move(s)){}

    battle_ship& operator = (battle_ship&& s){
      ship::operator = (move(s));
      do_battle_ship_only_move(move(s));
      return *this;
    }

    // Permit specifying a name...
    explicit battle_ship(string const& name):ship(name){}
    explicit battle_ship(string&& name):ship(name){}

    void sail() override{
      cout << get_type_name_addr() << " off to war!\n";
    }

    string get_ship_type() const override{
      return string("battle_ship");
    }

    virtual void fire_weapon(){
      cout << get_type_name_addr() << " firing cannon!\n";
    }

    protected:
      void do_battle_ship_only_move(battle_ship&&){}
};


template <typename T>
class cargo_ship: public virtual ship
{
  public:
    // All ships must have a name so prohibit the default constructor...
    cargo_ship() = delete;

    // Prohibit copies...
    cargo_ship(const cargo_ship&) = delete;
    cargo_ship& operator = (const cargo_ship&) = delete;

    // Permit moves...
    cargo_ship(cargo_ship&& s):ship(move(s)){
      this->cargo_ = move(s.cargo_);
    }

    cargo_ship& operator = (cargo_ship&& s){
      ship::operator = (move(s));
      do_cargo_ship_only_move(move(s));
      return *this;
    }

    // Permit specifying a name...
    explicit cargo_ship(string const& name):ship(name){}
    explicit cargo_ship(string&& name):ship(name){}

    template<typename Iter> explicit cargo_ship(string name, Iter first, Iter last):
      ship(name),cargo_(first,last){}

    void sail() override{
      cout << get_type_name_addr() << " setting sail.\n";
    }

    string get_ship_type() const override{
      return string("cargo_ship");
    }

    vector<T>& get_cargo(){
      return cargo_;
    }

    vector<T> const& const_get_cargo(){
      return cargo_;
    }

    protected:
      void do_cargo_ship_only_move(cargo_ship&& s){
        this->cargo_ = move(s.cargo_);
      }
      vector <T> cargo_;
};

template <typename T>
class smuggler_ship: public virtual cargo_ship<T>, public virtual battle_ship
{
  public:
    // All ships must have a name so prohibit the default constructor...
    smuggler_ship() = delete;

    // Prohibit copies...
    smuggler_ship(const smuggler_ship&) = delete;
    smuggler_ship& operator = (const smuggler_ship&) = delete;

    // Permit moves...
    smuggler_ship(smuggler_ship&& s):ship(move(s)),cargo_ship<T>(move(s)),battle_ship(move(s)){}

    smuggler_ship& operator = (smuggler_ship&& s){
      do_smuggler_ship_only_move(move(s));
      return *this;
    }

    // Permit specifying a name...
    explicit smuggler_ship(string const& name):ship(name),cargo_ship<T>(name),battle_ship(name){}
    explicit smuggler_ship(string&& name):ship(name),cargo_ship<T>(name),battle_ship(name){}

    void sail() override{
      cout << get_type_name_addr() << " off to pillage!\n";
    }

    string get_ship_type() const override{
      return string("smuggler_ship");
    }

    void fire_weapon() override{
      cout << get_type_name_addr() << " launching harpoon!\n";
    }

    void steal(ship& s){
      cargo_ship<T> *cs = dynamic_cast<cargo_ship<T>*>(&s);
      smuggler_ship *ss = dynamic_cast<smuggler_ship*>(&s);
      if (ss != nullptr){
        ostringstream buf;
        buf << get_type_name_addr()
            << " cannot steal from another "
            << ss->get_type_name_addr()
            << '!';
        throw runtime_error( buf.str() );
      }
      else if(cs != nullptr){
        cout << get_type_name_addr()
             << " is stealing half of "
             << cs->get_type_name_addr()
             << "!\n";
        auto middle = begin(cs->get_cargo()) + distance(begin(cs->get_cargo()), end(cs->get_cargo()))/2;

        for (auto e=middle; e!=end(cs->get_cargo()); ++e){
          this->cargo_.emplace_back(*move(e));
        }

         cs->get_cargo().erase(middle, end(cs->get_cargo()));
      }
      else {
        ostringstream buf;
        buf << get_type_name_addr()
            << " cannot steal from a "
            << s.get_type_name_addr()
            << '!';
        throw runtime_error( buf.str() );
      }
    }

    protected:
      void do_smuggler_ship_only_move(smuggler_ship&& s){
        do_ship_only_move(move(s));
        do_cargo_ship_only_move(move(s));
        do_battle_ship_only_move(move(s));
      }
};

template <typename ShipType, typename... Args>
std::unique_ptr<ship> create_ship(Args&&... args)
{
  return std::unique_ptr<ship>(new ShipType(std::forward<Args>(args)...));
}

template <typename ShipType, typename... Args>
std::unique_ptr<ShipType> create_ship_as_is(Args&&... args)
{
  return std::unique_ptr<ShipType>(new ShipType(std::forward<Args>(args)...));
}

void sail_all_ships(vector<unique_ptr<ship>>& ships)
{
  for (auto& ship : ships)
    ship->sail();
}

void fight(battle_ship& b1, battle_ship& b2)
{
  b1.fire_weapon();
  b2.fire_weapon();
}

void sail(unique_ptr<ship> const& s)
{
  s->sail();
}

void print_cargo(ship& s){
  cargo_ship<int> *cs = dynamic_cast<cargo_ship<int>*>(&s);
  if(cs != nullptr){
    auto cargo = cs->get_cargo();
    cout << "The contents of " << cs->get_name() << " cargo are :";
    for (auto it = cargo.begin(); it != cargo.end(); ++it)
      cout << ' ' << *it;
    cout << '\n';
  }
  else {
    cout << "ship has no cargo.\n";
  }
}

int main()
{
  // Using a unique_ptr to own each ship and ensure its eventual destruction...
  vector<unique_ptr<ship>> shipyard;
  shipyard.emplace_back(create_ship<cargo_ship<int>>("Storage Master"));
  shipyard.emplace_back(create_ship<battle_ship>("HMS Awesome"));
  shipyard.emplace_back(create_ship<smuggler_ship<int>>("Bounty Hunter"));

  // NOTE: If uncommented, the next line should compile...
  //vector<unique_ptr<ship>> shipyard_new_location(std::move(shipyard));

  // NOTE: If uncommented, the next line should NOT compile...
  //vector<unique_ptr<ship>> wont_work2(shipyard);

  // NOTE: If uncommented, the next declaration should NOT compile...
  /*vector<smuggler_ship<int>> wont_work2{
    smuggler_ship<int>("Thief 1 Ship"),
    smuggler_ship<int>("Thief 2 Ship")
  };*/

  // Anchors aweigh!
  cout << "Sail all ships...\n";
  sail_all_ships(shipyard);

  // Create a fight between two battle ships.
  cout << "\nFight between b1 and b2...\n";
  battle_ship b1("HMCS Hunter");
  battle_ship b2("SS Teacup");
  fight(b1, b2);

  // A battle ship fights a smuggler ship....
  cout << "\nFight b1 with last ship in shipyard...\n";
  fight(
    b1,
    dynamic_cast<smuggler_ship<int>&>(*shipyard.back())
  );

  cout << "\nSail one-by-one...\n";
  for (auto const& i : shipyard)
    sail(i);

  cout << "\nSteal cargo...\n";
  int myints[] = {16,2,77,29,35,50};
  vector<int> cargo (myints, myints + sizeof(myints) / sizeof(int) );
  auto ss = create_ship_as_is<smuggler_ship<int>>("Pirate Ship");
  auto cs = create_ship<cargo_ship<int>>("Cargo Ship",begin(cargo),end(cargo));
  auto bs = create_ship<battle_ship>("Non-Cargo Ship");

  //print_cargo(*cs);
  //print_cargo(*ss);
  ss->steal(*cs);
  //print_cargo(*cs);
  //print_cargo(*ss);
  try { ss->steal(*bs); } catch (exception& e) { cout << e.what() << '\n'; }
}
