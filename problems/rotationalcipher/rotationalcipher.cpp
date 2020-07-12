//
// Created by selva on 08-07-2020.
//

#include "rotationalcipher.h"

std::string rotational_cipher::rotationalCipher(
    std::string input, int rotationFactor) {
  std::string outp;
  char tchar='0';
  for(int i =0 ; i<input.length(); i++) {
    if(!isalnum(input[i])){
      outp.push_back(input[i]);
    }
    else{
      tchar = input[i];
      for(int i = 0; i<rotationFactor;i++ ){
        if(tchar == 'Z') {
          tchar = 'A';
          continue;
        }
        if(tchar == 'z') {
          tchar = 'a';
          continue;
        }
        if(tchar == '9') {
          tchar = '0';
          continue;
        }
        tchar = static_cast<char>(tchar+1);
      }
      outp.push_back(tchar);
    }
  }
  return outp;
}