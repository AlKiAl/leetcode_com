class Solution {

bool zeroAlphsbet(int count[]){

   for (char c = 'a'; c <= 'z'; c++) {

      if (count[c] != 0) { return false; }

   }

   return true; 
}

public:
   vector<int> findAnagrams(string_view s, string_view DesiredAnagr) { 
     
      vector<int> ans;
        
      if(s.size() < DesiredAnagr.size()){ return ans;}

      int count[1 + 'z'] = {}; // char of DesiredAnagr -, chars of s +

      for (char c : DesiredAnagr) { 
         count[c]--;
      }

      for (int j = 0; j < DesiredAnagr.size(); j++) { 
         const char c = s[j];
         count[c]++;
      }

      if(zeroAlphsbet(count)){ans.push_back(0);}


      for (int i = (int)DesiredAnagr.size(); i < (int)s.size()  ; i++) { 

         const char ToRemove = s[i - (int)DesiredAnagr.size()];
         const char ToAdd = s[i];
         --count[ToRemove];
         ++count[ToAdd];

         if (zeroAlphsbet(count)) {ans.push_back(i- (int)DesiredAnagr.size() + 1);}

      }

      return ans;
   }
} ;
