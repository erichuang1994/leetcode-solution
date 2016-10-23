class Solution {
public:
  string parseTernary(string expression) {

    if (expression[0] != 'T' && expression[0] != 'F')
      return expression;
    if (expression == "T" || expression == "F")
      return expression;
    int count = 0;
    for (int i = 1; i < expression.length(); ++i) {
      if (expression[i] == '?') {
        count++;
      } else if (expression[i] == ':') {
        count--;
      }
      if (count == 0) {
        if (expression[0] == 'T') {
          return parseTernary(expression.substr(2, i - 2));
        } else {
          return parseTernary(expression.substr(i + 1));
        }
      }
    }
    return "";
  }
};
