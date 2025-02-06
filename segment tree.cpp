
const int MX = 1e5+9;

int a[MX], st[4*MX];

void build(int id, int b, int e) {
    if(b == e) {
        st[id] = a[b];
        return;
    }
    int mid = (b+e) / 2, l_id = 2*id, r_id = l_id + 1;
    build(l_id,b,mid);
    build(r_id,mid+1,e);
    st[id] = st[l_id] + st[r_id];
}

void update(int id, int b, int e, int i, int val) {
    if(i < b || e < i) return;
    if(b == i && e == i) {
        st[id] = val;
        return;
    }
    int mid = (b+e) / 2, l_id = 2*id, r_id = l_id + 1;
    update(l_id,b,mid,i,val);
    update(r_id,mid+1,e,i,val);
    st[id] = st[l_id] + st[r_id];
}

int query(int id, int b, int e, int i, int j) {
    if(j < b || e < i) return 0;
    if(b >= i && e <= j) return st[id];
    int mid = (b+e) / 2, l_id = 2*id, r_id = l_id + 1;
    return query(l_id,b,mid,i,j) + query(r_id,mid+1,e,i,j);
}
