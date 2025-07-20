#include<iostream>
#include<vector>
using namespace std;
class proc{
    public:
    int pid;
    int at,bt,ct,tat,wt,rt;
    bool isFinished=false;
    bool isStarted=false;
    int remainingtime;
    int priority;
};
int main(){
    int n;
    cout<<"enter number of process";
    cin>>n;
    vector<proc>p(n);
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        cout<<"enter arrival time and burst time and priority"<<endl;
        cin>>p[i].at>>p[i].bt>>p[i].priority;
        p[i].remainingtime=p[i].bt;
    }
    int current_time=0;
    int completed_count=0;
    vector <pair<int,int>>gantt;
    float avg_ct=0,avg_tat=0,avg_wt=0,avg_rt=0;
    while(completed_count<n){
        int low_num=1000;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(!p[i].isFinished && p[i].at<=current_time ){
                if(p[i].priority<low_num ||(p[i].priority==low_num && p[i].at <p[idx].at)){
                    low_num=p[i].priority;
                    idx=i;
                }
            }
        }

        if(idx!=-1){
            if(!p[idx].isStarted ){
                
            p[idx].rt=current_time-p[idx].at; 
            p[idx].isStarted=true;
            }
            gantt.push_back({p[idx].pid,current_time});
            p[idx].remainingtime--;
            if(p[idx].remainingtime==0){
                p[idx].ct=current_time+1;
                p[idx].tat=p[idx].ct-p[idx].at;
               p[idx].wt=p[idx].tat-p[idx].bt;
               p[idx].isFinished=true;
            avg_ct+=p[idx].ct;
            avg_tat+= p[idx].tat;
            avg_wt+=p[idx].wt;
            avg_rt+=p[idx].rt;
            completed_count++;
            } 
        }
        current_time++;
    }
    
    //table 
    cout<<"\npid|\tat|\tbt|\tprio\tct\ttat|\twt|\trt|<<\n";
    for(auto process:p){
    cout<<process.pid<<"\t"<<process.at<< "\t"<<process.bt<< "\t"<<process.priority<<"\t"<<process.ct<< "\t"<<process.tat<< "\t"<<process.wt<<"\t"<<process.rt<<endl;

   
    }
    cout<<"average completion time :"<<avg_ct/n<<endl;
    //gantt chart 
    cout<<"--------------------\n";
    for(auto pairs :gantt){
        cout<<pairs.first<<"\t";
    }
    cout<<endl;
    cout<<"0\t";

    for(auto pairs :gantt){
        cout<<pairs.second<<"\t";
    }
cout<<endl<<"-----------------------";
}