#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(int argc,char *argv[]){
    //string filename=argv[1];
    string pattern=argv[2];

    //cout<<pattern.size();
    ifstream in_file;
    in_file.open(argv[1]);
    if(in_file.fail()){
        cout<<"fuck off"<<endl;
        return 0;
    }
    string x;
    int looptimes;
    int matches=0;
    int tag=0;
    while(getline(in_file,x)){
        looptimes=x.size()-pattern.size();
        for(int i=0;i<looptimes;i++){
            tag=0;
            for(int j=0;j<pattern.size();j++){
                if(pattern[j]==x[i+j]){
                    continue;
                }else{
                    tag=1;
                    break;
                }
            }
            if(tag==0){
                matches+=1;
                i+=pattern.size();    
            }
        }
        //  cout<<"I in la!!"<<endl;
    }

    cout<<pattern<<" appears "<<matches<<" times"<<endl;
}
