implement: 

interface IServiceA
{
    string Get(int index);
    void Set(int index, string val);
    void SetAll(string val);
    void Init(int maxCount);
}


Get, Set and SetAll – complexity of O(1) and no new memory allocation

example usage:
Init(100)
Set(1, "1")
SetAll("2")
Set(2, "3")
Set(32, "4")
Get(1) -> "2"
Get(2) -> "3"