// update (1,0,n-1,l,r);
// id always 1 not 0;
const int MX = 1e5;

int a[MX], st[4*MX], prop[4*MX];

void build(int id, int b, int e)
{
    if(b == e)
    {
        st[id] = a[b];
        return;
    }

    int mid = (b+e) / 2, l_id = 2*id, r_id = l_id + 1;
    build(l_id,b,mid);
    build(r_id,mid+1,e);

    st[id] = st[l_id] + st[r_id];
}

void propagate(int id, int b, int e)
{
    if(b != e)
    {
        int l_id = 2*id, r_id = l_id + 1;
        prop[l_id] += prop[id];
        prop[r_id] += prop[id];
    }

    st[id] += (prop[id] * (e-b+1));
    prop[id] = 0;
}

void update(int id, int b, int e, int i, int j, int val)
{
    if(prop[id])
    {
        propagate(id,b,e);
    }

    if(j < b || e < i) return;

    if(b >= i && e <= j)
    {
        prop[id] = val;
        propagate(id,b,e);
        return;
    }

    int mid = (b+e) / 2, l_id = 2*id, r_id = l_id + 1;
    update(l_id,b,mid,i,j,val);
    update(r_id,mid+1,e,i,j,val);

    st[id] = st[l_id] + st[r_id];
}

int query(int id, int b, int e, int i, int j)
{
    if(prop[id])
    {
        propagate(id,b,e);
    }

    if(j < b || e < i) return 0;

    if(b >= i && e <= j) return st[id];

    int mid = (b+e) / 2, l_id = 2*id, r_id = l_id + 1;
    return query(l_id,b,mid,i,j) + query(r_id,mid+1,e,i,j);
}
