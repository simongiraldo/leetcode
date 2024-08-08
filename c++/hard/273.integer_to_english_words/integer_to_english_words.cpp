#include <vector>

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        vector<string> delimeterNums = {"Billion", "Hundred", "two digits", "Million", "Hundred", "two digits", "Thousand", "Hundred", "two digits"};
        vector<string> twoDigitNums = {"", "teen", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> normalNums = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

        if(num % 10 == num) {
            return normalNums[num];
        }

        int separator = 1000000000;
        string word = "";

        for(int i = 0; i < delimeterNums.size(); i++) {
            int toWord = num / separator;

            if(toWord > 0) {
                word += word != "" ? " " : "";

                if(delimeterNums[i] == "two digits" && twoDigitNums[toWord] == "teen") {
                    num = num % separator;
                    separator /= 10;

                    word += teens[num / separator];
                    word += i < delimeterNums.size() - 1 ? " "+delimeterNums[++i] : "";
                } else if (delimeterNums[i] == "two digits") {
                    word += twoDigitNums[toWord];

                    int nextNumber = (num%separator) / (separator/10);
                    if(nextNumber == 0 && separator > 10) {
                        num = num % separator;
                        separator /= 10;
                        word += " " + delimeterNums[++i];
                    }
                } else {
                    word += normalNums[toWord] + " " + delimeterNums[i];

                    if(i < delimeterNums.size()-2) {
                        int nextNumber = (num%separator) / (separator/10);
                        int secondNextNumber = (num%separator) / (separator/100);

                        if(delimeterNums[i] == "Hundred" && nextNumber == 0 && secondNextNumber == 0) {
                            word += " " + delimeterNums[i+2];
                        }
                    }
                }
            }

            num = num % separator;
            separator /= 10;
        }

        if(num > 0 ) {
            word += " " + normalNums[num];
        }

        return word;
    }
};