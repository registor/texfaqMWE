//函数定义
void PrintGrade(int iScore)
{
    switch(iScore / 10)
    {
    case 10:
        printf("Excellent\n");
        break;
    case 9:
        printf("Excellent\n");
        break;
    case 8:
        printf("Good\n");
        break;
    case 7:
        printf("Average\n");
        break;
    case 6:
        printf("Poor\n");
        break;
    default:
        printf("Failing\n");
        break;
    }
}
