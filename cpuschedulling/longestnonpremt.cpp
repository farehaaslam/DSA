#include<iostream>
#include<vector>
using namespace std;
class proc{
    public:
    int pid;
    int at,bt,ct,tat,wt,rt;
    bool isFinished=false;
};
int main(){
    int n;
    cout<<"enter number of process";
    cin>>n;
    vector<proc>p(n);
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        cout<<"enter arrival time and burst time"<<endl;
        cin>>p[i].at>>p[i].bt;
    }
    int current_time=0;
    int completed_count=0;
    vector <pair<int,int>>gantt;
    float avg_ct=0,avg_tat=0,avg_wt=0,avg_rt=0;
    while(completed_count<n){
        int max_bt=-1;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(!p[i].isFinished && p[i].at<=current_time ){
                if(p[i].bt>max_bt){
                    max_bt=p[i].bt;
                    idx=i;
                }
            }
        }
        if(idx!=-1){
            p[idx].ct=current_time+p[idx].bt;
            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;
            p[idx].rt=p[idx].wt;
            current_time=p[idx].ct;
            p[idx].isFinished=true;
            avg_ct+=p[idx].ct;
            avg_tat+= p[idx].tat;
            avg_wt+=p[idx].wt;
            avg_rt+=p[idx].rt;
            gantt.push_back({idx+1,p[idx].ct});
            completed_count++;

        }
        else{
            current_time++;
        }
    }
    
    //table 
    cout<<"\npid|\tat|\tbt|\tct\ttat|\twt|\trt|<<\n";
    for(auto process:p){
    cout<<process.pid<<"\t"<<process.at<< "\t"<<process.bt<< "\t"<<process.ct<< "\t"<<process.tat<< "\t"<<process.wt<<"\t"<<process.rt<<endl;

   
    }
    cout<<"average completion time :"<<avg_ct/n<<endl;
    //gantt chart 
    cout<<"--------------------"<<endl;
    for(auto pairs :gantt){
        cout<<pairs.first<<"\t";
    }
    cout<<endl;

    for(auto pairs :gantt){
        cout<<pairs.second<<"\t";
    }
cout<<endl<<"-----------------------";
}