class Solution {
public:
    string truncateSentence(string s, int k) {
        s.push_back(' ');
        string res="";
        for(int i=0;i<s.size();++i){
            string tmp="";
            while(s[i]!=' ')
                tmp+=s[i++];
            if(k-->0)
                res+=res.size()?" "+tmp:tmp;
        }
        return res;
    }
};


class Solution {
public:
    string truncateSentence(string s, int k) {
        for(int i=0;i<s.size();++i)
            if(s[i]==' '&&--k==0)
                return s.substr(0,i);
        return s;
    }
};