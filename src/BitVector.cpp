#include "template.cpp"

class BitVector{
    vector<int>sum;
    vector<uint64_t>bit;
public:
    int rank(bool val,int idx){
        uint64_t mask=((uint64_t)1<<(idx&((1<<6)-1)))-1;
        int res=sum[idx>>6]+__builtin_popcountll(bit[idx>>6]&mask);
        return (val?res:idx-res);
    }
    BitVector(vector<bool>&v){
        int sz=(len(v)>>6)+1;
        bit.assign(sz,0);
        sum.assign(sz,0);
        rep(i,len(v)){
            bit[i>>6]|=(uint64_t)(v[i])<<(i&((1<<6)-1));
        }
        rep(i,sz-1){
            sum[i+1]=sum[i]+__builtin_popcountll(bit[i]);
        }
    }
};