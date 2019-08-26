#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
        int n;
        string temp;
        map<char,int> temp2;
        vector<map<char,int>> strings={};
        vector<string> strings2={};
        vector<string> answers;
        cin>>n;
        for (int i=-2;i<n;i++){
                while(getline(cin,temp)){
                        if(temp==""){
                                break;
                        }
                        for (int o=0;o<temp.length();o++){
                                if(temp[o]!=' ')
                                        temp2[temp[o]]++;
                        }
                        strings2.push_back(temp);
                        strings.push_back(temp2);
                        temp2.clear();
                }


                for (int j=0;j<strings.size();j++){
                        for (int u=j+1;u<strings.size();u++){
                                if(strings[j]==strings[u]){
                                        if(strings2[j].compare(strings2[u])<0)
                                                answers.push_back(strings2[j]+" = "+strings2[u]+"\n");
                                        else
                                                answers.push_back(strings2[u]+" = "+strings2[j]+"\n");
                                }
                        }
                }
                if(i>0)
                    answers.push_back("\n");
                sort(answers.begin(),answers.end());
                for (auto it=answers.begin();it!=answers.end();it++)
                        cout<<*it;
        strings.clear();
        strings2.clear();
        answers.clear();
        }

        return 0;
}
