#include <iostream>
#include <string>
#include "managementSys.h"
#include "manageSysFunction.cpp"

int main() {
    vector<Person> ones;
    Person user;
    Initial(ones);
    bool flag = IfContinue();
    if (!flag) return 0;
//    string a = "identical";
//    string b = "ID";
//    string c = "hdu20010011";
//    for (int i = 0; i < ones.size(); i++) {
//        cout << ones[i].GetName() << endl;
//        if ((i + 1) % 5 == 0) cout << endl;
//    }

//    cout << ones[4].GetName() << endl;
//    cout << user.FindName(ones, a) << endl;
//    cout << user.Find(ones, b, c) << endl;
//    Person temp = Random(ones);
//    cout << temp.GetName() << endl;

    vector<Person> feedBack = Rand(ones);
}
