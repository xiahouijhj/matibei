//整数二分模板1
int bsearch_1(int l,int r)
{
    while(l < r)
    {
        mid = (l+r)>>1;
        if(check(mid))  r = mid;
        else    l = mid+1;
    }
    return l;
}

//整数二分模板2
int bsearch_2(int l,int r)
{
    while(l < r)
    {
        mid = (l+r+1)>>1;
        if(check(mid))  r = mid-1;
        else    l = mid;
    }
    return l;
}
//实数二分答案
double bsearch_d1(double l,double r)
{
    double esp = 1e-6;//1e -(k+2),k为保留k位小数
    double mid = (l+r)*0.5;//或mid = (l+r)/2;此时注意不能使用位运算
    while(r-l > esp)
    {
        if(check(mid))  r = mid;//去掉右区间
        else    l = mid;//去掉左区间
    }
    return l;
}
