class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int teams = votes[0].size();
        string s = votes[0];
        vector<vector<int>> freq(26, vector<int>(teams,0));
        
        for(int i=0; i<votes.size(); i++){
            for(int j=0; j<votes[i].size(); j++){
                char c = votes[i][j];
                freq[c-'A'][j]++; 
            }
        }
        
        //lambda
        sort(s.begin(),s.end(),[=](char &a, char &b){
            for(int i=0; i<freq[0].size(); i++){
                if(freq[a-'A'][i] == freq[b-'A'][i]) continue;
                return freq[a-'A'][i] > freq[b-'A'][i];
            }
            return a<b;
        });
        return s;
    }
};