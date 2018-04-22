#include <bits/stdc++.h>
#include <string>
using namespace std;


/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */
    //AM -no change
    if(s.substr(8,10)=="AM"){
        if(stoi(s.substr(0,2))==12)
            return "00"+s.substr(2,6);
        return s.substr(0,8);
    }
        
    //PM
    //return ((((stoi(s.substr(0,2))+12)==24)?"00":to_string(stoi(s.substr(0,2))+12)) +s.substr(2,6));
    return ((stoi(s.substr(0,2))==12?"12":to_string(stoi(s.substr(0,2))+12))+s.substr(2,6));

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

