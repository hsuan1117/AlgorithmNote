# 迴文
看到Jonason大大寫的簡潔判斷，就先記錄一下吧!

```cpp
bool check(int x,int y,string str){
    if(x==y)return true;
    for(int i=x,j=y;i<=j;i++,j--){
        if(str[i]!=str[j])return false;
    }
    return true;
}
```
