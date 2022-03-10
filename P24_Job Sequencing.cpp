#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(), cout.tie();
    cout << "Enter the number of jobs and press  Enter\n" ;
    int n;
    cin >> n;
    cout << "Enter the jobId deadline profit of each job\n";
    vector<vector<int>>  jobs;
    int maxDeadline = 0;
    for(int i=0;i<n;i++){
        char jobId ;
        int deadline,profit;
        cin >> jobId >> deadline >> profit;
        jobs.push_back({profit,deadline,(int)jobId});
        if (deadline> maxDeadline ) maxDeadline = deadline;


    }
    sort(jobs.begin(),jobs.end(),greater<>());
    vector<vector<int>> takenJobs(maxDeadline,{-10000,-1,-1});
    for (auto & job : jobs){
        for (int d = job[1]-1;d >= 0;d-- ){
            if (takenJobs[d][1] == -1){
                takenJobs[d][0]  =  job[0];
                takenJobs[d][1]  =  job[1];
                takenJobs[d][2]  =  job[2];
                break;
            }
        }
    }
    for (auto & takenJob : takenJobs){
        if (takenJob[1] != -1)
            cout << (char)(takenJob[2]) << " " ;
    }
    return 0;
}