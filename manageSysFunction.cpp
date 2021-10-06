//
// Created by MelodyInFolwingTime on 2021/9/25.
//

#include "managementSys.h"

Person::Person(string oneId, string oneName, string oneDepartment,
               string oneStuNumber, string oneImg) : ID(oneId), name(oneName),
                                                     department(oneDepartment), stuNumber(oneStuNumber),
                                                     imgUrl(oneImg) {}

void Person::operator=(const Person &ones) {
    ID = ones.ID;
    name = ones.name;
    department = ones.department;
    stuNumber = ones.stuNumber;
    imgUrl = ones.imgUrl;
}

string Person::GetID() {
    return ID;
}

string Person::GetName() {
    return name;
}

string Person::GetImg() {
    return imgUrl;
}

string Person::GetStuNumber() {
    return stuNumber;
}

string Person::GetDepartment() {
    return department;
}

bool Person::FindName(const vector<Person> &ones, string &value) {
    for (int i = 0; i < ones.size(); ++i) {
        if (ones[i].name == value)
            return true;
    }
    return false;
}

bool Person::FindID(const vector<Person> &ones, string &value) {
    for (int i = 0; i < ones.size(); ++i) {
        if (ones[i].ID == value)
            return true;
    }
    return false;
}

bool Person::FindImgUrl(const vector<Person> &ones, string &value) {
    for (int i = 0; i < ones.size(); ++i) {
        if (ones[i].imgUrl == value)
            return true;
    }
    return false;
}

bool Person::FindStuNumber(const vector<Person> &ones, string &value) {
    for (int i = 0; i < ones.size(); ++i) {
        if (ones[i].stuNumber == value)
            return true;
    }
    return false;
}

bool Person::FindDepartment(const vector<Person> &ones, string &value) {
    for (int i = 0; i < ones.size(); ++i) {
        if (ones[i].department == value)
            return true;
    }
    return false;
}

bool Person::Find(vector<Person> &ones, string &key, string &value) {
    if (key == "name")
        return FindName(ones, value);
    else if (key == "ID")
        return FindID(ones, value);
    else if (key == "Img")
        return FindImgUrl(ones, value);
    else if (key == "StuNumber")
        return FindStuNumber(ones, value);
        //    else if (key == "Department")
    else
        return FindDepartment(ones, value);
}

bool cmp(Person a, Person b) { return a.ID < b.ID; }

//Person Random(const vector<Person> &ones) {//为什么返回都是同样的，放弃了
////    time_t t;
////    srand((unsigned) time(&t));
////    int i = rand();
////    cout << i << endl;
////    i %= (ones.size());
//    default_random_engine e;
//    uniform_int_distribution<unsigned> x;
//    int i = x(e) % ones.size();
//    cout << i << endl << ones.size() << endl;
//    return ones[i];
//}

vector<int> Random(int n) {
    default_random_engine e;
    uniform_int_distribution<unsigned> x;
    vector<int> r(4);
    int j;
    for (int i = 0; i < 4; ++i) {
        j = x(e) % n;
        r[i] = j;
        cout << j << endl;
    }
    return r;
}

bool Initial(vector<Person> &ones) {
    bool flag = ReadData(ones);
    sort(ones.begin(), ones.end(), cmp);
    return flag;
}

bool ReadData(vector<Person> &ones) {
    Person temp;
    // 以读模式打开文件
    ifstream infile;
    cout << "Reading from the file" << endl;
    infile.open("D:\\Code_Learning\\CandC++Learn\\DataStructure\\poBing\\persons.txt", ios::in);
    if (!infile) {
        cerr << "error: unable to open result file" << endl;
        return false;
    }
    while (!infile.eof()) {
        string lineText;
        getline(infile, lineText);
        temp.ID = lineText;
        getline(infile, lineText);
        temp.name = lineText;
        getline(infile, lineText);
        temp.department = lineText;
        getline(infile, lineText);
        temp.stuNumber = lineText;
        getline(infile, lineText);
        temp.imgUrl = lineText;
        ones.push_back(temp);
    }
    // 关闭打开的文件
    infile.close();
    cout << "Successfully Get the Data!" << endl;
    cout << "push Enter to continue...";
    getchar();
    return true;
}

bool IfContinue() {
    system("cls");
    cout << "cin 'e' to exit or push any other key to continue..." << endl;
//    string key;
//    cin >> key;
    char key = getchar();
//    if (key == "END" || key == "end" || key == "End")
    system("cls");
    if (key == 'e' || key == 'E')
        return false;
    return true;
}

vector<Person> Rand(vector<Person> &ones) {
    map<char, Person> ans;
    vector<Person> wrongChoose;
    vector<int> r = Random(ones.size());
//    ans['A'] = Random(ones);
//    ans['B'] = Random(ones);
//    while (ans['B'].GetID() != ans['A'].GetID())
//        ans['B'] = Random(ones);
//    ans['C'] = Random(ones);
//    while (ans['C'].GetID() != ans['A'].GetID() && ans['C'].GetID() != ans['B'].GetID())
//        ans['C'] = Random(ones);
//    ans['D'] = Random(ones);
//    while (ans['D'].GetID() != ans['A'].GetID() && ans['D'].GetID() != ans['B'].GetID() &&
//           ans['D'].GetID() != ans['C'].GetID())
//        ans['D'] = Random(ones);
    int i = 0;
    ans['A'] = ones[r[i++]];
    ans['B'] = ones[r[i++]];
    ans['C'] = ones[r[i++]];
    ans['D'] = ones[r[i++]];
    MainFunc(wrongChoose, ans);
    return wrongChoose;
}

void MainFunc(vector<Person> &wrongChoose, map<char, Person> ans) {
    bool flag = true;
    char answer = rand() % 4 + 'A';
    while (flag) {
        system("cls");
        cout << "我是谁？" << endl;
        cout << ans[answer].GetImg() << endl << endl;
        cout << "A." << ans['A'].GetName() << endl;
        cout << "B." << ans['A'].GetName() << endl;
        cout << "C." << ans['A'].GetName() << endl;
        cout << "D." << ans['A'].GetName() << endl;
        char choose;
        cin >> choose;
        while (choose != 'A' && choose != 'B' && choose != 'C' && choose != 'D'
               && choose != 'a' && choose != 'b' && choose != 'c' && choose != 'd') {
            cout << "没有这个选项吧，请重新输入" << endl;
            cin >> choose;
        }
        if (choose != answer || choose != (answer - 'A' + 'a')) {
            cout << "选错啦" << endl << "这是" << ans[answer].GetName() << endl;
            wrongChoose.push_back(ans[answer]);
            getchar();
        }
        flag = IfContinue();
        system("cls");
    }
}