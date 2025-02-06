
using pii = pair<int,int>;

pii st[4*MAXN];

pii combine(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) return a;
    if (b.first > a.first) return b;
    return make_pair(a.first, a.second + b.second);
}

void update(int id, int b, int e, int i, pii val) {
    if(i < b || e < i) return;
    if(b == i && e == i) {
        if (st[id].first == val.first) {
            st[id].second += val.second;
        }
        else st[id] = val;
        return;
    }
    int mid = (b+e) / 2, l_id = 2*id, r_id = l_id + 1;
    update(l_id,b,mid,i,val);
    update(r_id,mid+1,e,i,val);
    st[id] = combine(st[l_id], st[r_id]);
}

pii query(int id, int b, int e, int i, int j) {
    if(j < b || e < i) return {0,0};
    if(b >= i && e <= j) return st[id];
    int mid = (b+e) / 2, l_id = 2*id, r_id = l_id + 1;
    return combine (query(l_id,b,mid,i,j), query(r_id,mid+1,e,i,j));
}
