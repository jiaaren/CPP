class Sample1
{
    Sample1();
    ~Sample1();
};

struct Sample2
{
    Sample2();
    ~Sample2();
};

int main(void)
{
    // expect error since class is private by default
    Sample1 s1;
    Sample2 s2;
}