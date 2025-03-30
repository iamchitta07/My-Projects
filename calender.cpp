#include <bits/stdc++.h>
using namespace std;

bool flag(int n3){
    bool flag = false; // not a LeapYear
    if((n3%4==0)||(n3%400==0 && n3%100!=0)) flag = true; // LeapYear
    return flag;
}

int l2d(int n3){
    return n3%100;
}

int l2dQ(int n3){
    return l2d(n3)/4;
}

int mnthCode(int n2){
    switch(n2){
        case 10:
        case 1: return 1;
        case 2:
        case 11:
        case 3: return 4;
        case 4:
        case 7: return 0;
        case 5: return 2;
        case 6: return 5;
        case 8: return 3;
    } return 6;
}

int mnthCodeLeapYr(int n2){
    switch(n2){
        case 1:
        case 4:
        case 7: return 0;
        case 10: return 1;
        case 5: return 2;
        case 2:
        case 8: return 3;
        case 11:
        case 3: return 4;        
        case 6: return 5;
    } return 6;
}

int yrCode(int n3){
    int m = (n3/100)%4;
    switch(m){
        case 0: return 6;
        case 1: return 4;
        case 2: return 2;
    } return 0;
}

int sum(int n2,int n3){
    return (1+mnthCode(n2)+yrCode(n3)+l2d(n3)+l2dQ(n3))%7;
}

int sumLeapYr(int n2,int n3){
    return (1+mnthCodeLeapYr(n2)+yrCode(n3)+l2d(n3)+l2dQ(n3))%7;
}

void display(vector<vector<string>>& arr) {
    cout<<"\n";
    for(auto e1:arr) {
        for(auto ele:e1) cout<<ele<<" ";
        cout<<"\n";
    }
}

void buildCalender(int mnth,int yr) {
    int num;
    vector<int> month;
    if(flag(yr)) {
        num = sumLeapYr(mnth,yr);
        month = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    } else {
        num = sum(mnth,yr);
        month = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    } num = (num+6)%7;
    vector<vector<string>> arr;
    arr.push_back({"S ","M ","T ","W ","T ","F ","S "});
    int n,idx = 1;
    while(idx<=month[mnth]) {
        vector<string> hel;
        if(idx==1) {
            for(int i=0;i<num;i++) hel.push_back("  ");
            for(n=num;n!=7;n++) {
                string a = to_string(idx);
                if(idx<=9) a+=' ';
                hel.push_back(a);
                idx++;
            } n = 0; arr.push_back(hel);
        } else {
            for(n=0;idx<=month[mnth] and n!=7;idx++,n++) {
                string a = to_string(idx);
                if(idx<=9) a+=' ';
                hel.push_back(a);
            } 
            arr.push_back(hel);
            
        } 
    } display(arr);
}

int main(){
    int yr,mnth;
    cout<<"Enter Year: ";
    cin>>yr;

    cout<<"1. January"<<endl;
    cout<<"2. February"<<endl;
    cout<<"3. March"<<endl;
    cout<<"4. April"<<endl;
    cout<<"5. May"<<endl;
    cout<<"6. June"<<endl;
    cout<<"7. July"<<endl;
    cout<<"8. August"<<endl;
    cout<<"9. September"<<endl;
    cout<<"10. October"<<endl;
    cout<<"11. November"<<endl;
    cout<<"12. December"<<endl;
    cout<<"Select Month: ";
    cin>>mnth;

    buildCalender(mnth,yr);
    return 0;
}

// Created by @imchitta07