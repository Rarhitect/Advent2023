#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int line_value(const std::string& line){
    std::vector<int> digits;
    int value = 0;
    for (auto element: line){
        if((int)element >= 48 and (int)element <= 57){
            int int_element = element - '0';
            digits.push_back(int_element);
        }
    }
    if (sizeof(digits) > 0){
        /*for (auto & digit: digits){
            std::cout << digit << " ";
        }*/
        //std::cout << std::endl;
        //std::cout << "First and last digits are:" << digits[0] << " " << digits[digits.size()-1] << std::endl;
        value = value + digits[0] * 10 + digits[digits.size()-1];
    }
    return value;
}

int main(){
    std::fstream input_file;
    input_file.open("input.txt", std::ios::in);
    int calibration_value = 0;
    if (input_file.is_open()){ //checking whether the file is open
        std::string line;
        while(getline(input_file, line)){ //read data from file object and put it into string.
            auto LV = line_value(line);
            std::cout << line << std::endl;
            std::cout << "From this line I receive a CL = " << LV;
            calibration_value = calibration_value + LV;
            std::cout << "\nThus, current calibration value = " << calibration_value << std::endl;
            std::cout << std::endl;
      }
      input_file.close(); //close the file object.
   }
   std::cout << "Finally CL = " << calibration_value << std::endl;

}