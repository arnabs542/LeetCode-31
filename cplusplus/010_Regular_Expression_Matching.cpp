/* Solution 1 : Dynamic programming */
class Solution {
public:
    bool isMatch(string s, string p) {
        const std::size_t s_size(s.size()), p_size(p.size());
        std::vector< std::vector<bool> > is_match(s_size+1,std::vector<bool>(p_size+1,false));
        is_match[0][0] = true;
        
        for (std::size_t i=1;i<=p_size;++i) {
            is_match[0][i] = p[i-1]=='*' && is_match[0][i-2];
        }
        
        for (std::size_t i=1;i<=s_size;++i) {
            for (std::size_t j=1;j<=p_size;++j) {
                if (p[j-1]=='*') {
                    // when p's char is *, we only need consider two conditions.
                    // First, * match 0 times ,use * to counteract previous char, sort of like deleting it.
                    // Second, * match >=1 times, as long as the char before * in p can match the current char in s, 
                    // * can be used to match current char in s, we just need check is_match[i-1][j]
                    is_match[i][j] = is_match[i][j-2] // delete pre char
                                    || is_match[i-1][j] && (s[i-1]==p[j-2]||p[j-2]=='.'); 
                } else {
                    is_match[i][j] = is_match[i-1][j-1] && ( s[i-1]==p[j-1] || p[j-1]=='.');
                }
            }
        }
        
        return is_match[s_size][p_size];
    }
};

/* Solution 2 : this one has not been completed, not working */
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s,p,0,0);
    }
private:
    bool isMatch(const std::string & s, const std::string & p, int six, int pix) {
        const int s_size(s.size()), p_size(p.size());
        int s_mark(-1),p_mark(-1);
        while (six<s_size) {
            if (pix+1<p_size && p[pix+1]=='*') {
                // Mark the position * appears and move pix forward
                s_mark = six;
                p_mark = pix;
                pix+=2;
            } else {
                if (pix<p_size && (s[six]==p[pix] || p[pix]=='.') ) {
                    ++ six;
                    ++ pix;
                } else {
                    if (p_mark!=-1) {
                        six = s_mark, pix = p_mark;
                       if (s[s_mark]!=p[p_mark] && p[p_mark]!='.') {// * cant even match one
                           return false;
                       } else {
                           ++ s_mark; // use * to match one 
                           six = s_mark;
                           pix +=2 ;
                       }
                    } else {
                        return false;
                    }
                }
            }
        }
        while(pix+1<p_size && p[pix+1]=='*') pix+=2; // keep skipping "x*"
        return pix == p_size;
    }
};
