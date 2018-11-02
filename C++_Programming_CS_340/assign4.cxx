#include <map>
#include <stdexcept>
#include <memory>
#include <tuple>
#include <limits>
#include <iostream>

using namespace std;
using uint_type = unsigned long long;

class ack
{
  public:
    using tuple_type = tuple<uint_type, uint_type>;

    uint_type operator ()(uint_type const& m, uint_type const& n) const
    {
      return calculate(make_tuple(m,n));
    }

    uint_type calculate(tuple_type const& args) const {
      if ( cache_.find(args) == cache_.end() ) {
        // not found
        uint_type retval;
        uint_type const m = get<0>(args);
        uint_type const n = get<1>(args);

        if (m == 0){
          if (n < numeric_limits<uint_type>::max())
            retval = n+1;
          else
            throw range_error("ack::uint_type overflow");
        }
        else if ((m > 0) & (n == 0)) {
          retval = calculate(make_tuple(m-1, 1));
        }
        else if ((m > 0) & (n > 0)) {
          retval = calculate(make_tuple(m-1,calculate(make_tuple(m,n-1))));
        }

        cache_.insert({args,retval});
        return retval;

      }
      else {
        // found
        return cache_.find(args)->second;
      }
    }

  private:
    static map<tuple_type, uint_type> cache_;
};

map<ack::tuple_type, uint_type> ack::cache_;

int main()
{
using std::cout;

  ack f;

  for (uint_type m=0; m != 5; ++m)
  {
    for (uint_type n=0; n != 10; ++n)
    {
      cout << "f(" << m << ',' << n << ") = ";
      try
      {
        cout << f(m,n) << '\n';
      }
      catch (std::range_error &e)
      {
        cout << e.what() << '\n';
      }
      catch (std::bad_alloc &e)
      {
        cout << e.what() << '\n';
      }
      catch (...)
      {
        cout << "<UNKNOWN ERROR>\n";
      }
    }
    cout << '\n';
  }
}
