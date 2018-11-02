#include <string>    // for std::string
#include <locale>    // for std::isspace, std::alpha
#include <algorithm> // for std::find_if_not
#include <iostream>  // for std::cerr, std::cout
#include <fstream>   // for std::ifstream
#include <sstream>   // for std::ostringstream
#include <utility>   // for std::pair and std::make_pair
#include <iterator>  // for std::ostreambuf_iterator

using namespace std;

// the following function is used to trim the string by returning
//  a pair of iterators pointing to the first none white space charcter
// and the last none white space character
template <typename TrimPredicate>
auto string_range_trim(string& str, TrimPredicate p) ->
  pair<
    string::iterator,  // typedef to string iterator type
    string::iterator   // typedef to string iterator type
  >
{
  // use find if not to iterate over string characters from end to begining
  // to find the last none white space character
  auto last_non_ws_iter = find_if_not(rbegin(str),rend(str), p).base();
  // find the first none white space charcter by iterating over string elements
  // from begining to end
  auto first_non_ws_iter = find_if_not(begin(str), last_non_ws_iter, p);
  // return the iterator pair pointing to the begining and the end of the trimmed string
  return std::make_pair(first_non_ws_iter, last_non_ws_iter);
}

// the following function is used to read lines from the input stream
// and format them by filtering out comment lines that start with "#"
// and stitch lines together if they are a continuation of the previous line.
// this is done by finding if a line is ending with "\"

auto read_next_termcap_entry(istream& is) ->
  std::pair<bool, string>
{
  // define a buffer to store read lines and keep adding as long as the lines are a
  // continutation
  ostringstream buffer;
  auto loc = is.getloc();
  buffer.imbue(loc);
  bool data = false; // set to true when there is data in buffer
  bool continued_line = true; // set to true if line is continued
  for (string line; (!data || continued_line) && getline(is,line);)
  {
    continued_line = false;
    // filter out empty lines
    if (line.empty())
      continue;

    // remove white space from at the begining and end of line
    auto trimmed_range = string_range_trim(line,
      [loc](auto ch){
        return isspace(ch, loc);
      }
    );

    // make sure that trimmed line is not empty
    if (trimmed_range.first == trimmed_range.second)
      continue;

    // ignore comment lines which start with "#"
    if (*trimmed_range.first == '#')
      continue;

    // check if line is ending with "\" which would indicate that
    // it has continuation and stitch the next line to it after removing the "\"
    auto last_char_iter = trimmed_range.second;
    last_char_iter--;
    if (*last_char_iter == '\\')
    {
      continued_line = true;
      if (trimmed_range.first == last_char_iter)
        continue;
      trimmed_range.second = last_char_iter;
    }

    // check if line is a header line by checking that it has an alphabet character at the begining
    bool const header_line = isalpha(*trimmed_range.first, loc);

    // check if line is a capbility line by checking if it starts with a tab
    bool const capability_line =
      find(begin(line),trimmed_range.first,'\t')!= trimmed_range.first;

    // add formatted string to the buffer
    if (header_line || capability_line)
    {
      data = true;
      copy(
        trimmed_range.first,
        trimmed_range.second,
        ostreambuf_iterator<char>(buffer));
    }
  }

  // return the buffer string
  return {data, buffer.str()};
}

int main(int argc, char *argv[])
{
  // check if an argument was passed during program call
  // if no input was passed, program would output an error usage message
  if (argc != 2)
  {
    cerr << "Usage: " << argv[0] << " <termcap_db_file>\n";
    return 1;
  }

  // open passed argument filename for reading
  ifstream in(argv[1]);

  // check if file was opened correctly, if not an erro message is issued
  if (!in)
  {
    cerr << "Unable to open file. Aborting.\n";
    return 2;
  }

  // print out resulted formated termcap text
  for (auto result = read_next_termcap_entry(in);
  result.first;
  result = read_next_termcap_entry(in))
    cout << result.second << '\n';

  // return 0 to indicate that program ran successfuly
  return 0;
}
