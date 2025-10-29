// class Solution {
// public:
//     inline int lengthOfLongestSubstring(string s) const noexcept {
//         bool mask[128] = {false};
//         int max=0,l=0,r=0;
//         while(r<(int)s.size()){
//             if(mask[(int)s[r]]){
//                 mask[(int)s[l]]=false;
//                 ++l;
//             }else{
//                 mask[(int)s[r]]=true;
//                 ++r;
//                 int a=r-l;
//                 max=a^((a^max)&-(a<max));
//             }
//         }
//         return max;
//     }
// };