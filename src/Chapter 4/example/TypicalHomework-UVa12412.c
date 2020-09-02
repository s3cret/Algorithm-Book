#include <stdio.h>
#include <string.h>

#ifdef LOCAL
#include <My_util.h>
#endif

#define EPS 1e-5
#define maxn 1000
#define maxl 100
char SID[maxn][maxl], name[maxn][maxl];
int CID[maxn];
int score[maxn][5], removed[maxn], indx = 0, n = 0;

int rank(int i);
void print_menu();
void add();
void remove_query(int op);
void show_ranking();
void show_statistics();

int main()
{

#ifdef LOCAL
    char filename[sizeof(__FILE__) + 2];
    get_input_filename(filename, __FILE__);
    freopen(filename, "r", stdin);
    get_output_filename(filename);
    freopen(filename, "w", stdout);
#endif

    memset(SID, 0, sizeof(SID));
    memset(CID, 0, sizeof(CID));
    memset(SID, 0, sizeof(SID));
    memset(SID, 0, sizeof(SID));
    memset(SID, 0, sizeof(SID));

    int i;
    while (1)
    {
        print_menu();
        printf("n=%d\n", n);
        scanf("%d", &i);
        if (i == 0)
            return 0;

        switch (i)
        {
        case 1:
            add();
            break;
        case 2:
            remove_query(0);
            break;
        case 3:
            remove_query(1);
            break;
        case 4:
            show_ranking();
            break;
        case 5:
            show_statistics();
            break;
        }
    }

    return 0;
}

void add()
{
    int c, m, e, p;
    char dup[40] = "Duplicated SID";

    while (1)
    {
        printf("Please enter SID, CID, name and four scores. Enter 0 to finish.\n");
        scanf("%s", SID[indx]);
        if (strcmp(SID[indx], "0") == 0)
            break;

        for (int i = 0; i < maxn; i++)
        {
            if (i == indx || !removed[i])
            {
                continue;
            }

            if (strcmp(SID[i], SID[indx]) == 0)
            {
                printf("Duplicated SID.\n");
                continue;
            }
        }

        scanf("%d", &CID[indx]);
        scanf("%s", name[indx]);
        scanf("%d%d%d%d", &c, &m, &e, &p);
        score[indx][0] = c;
        score[indx][1] = m;
        score[indx][2] = e;
        score[indx][3] = p;
        score[indx][4] = c + m + e + p;

        indx++;
        n++;
    }
}

void remove_query(int op)
{
    char s[11];
    while (1)
    {
        printf("Please enter SID or name, Enter 0 to finish.\n");
        scanf("%s", s);
        if (strcmp(s, "0") == 0)
            break;

        int r = 0;
        for (int i = 0; i < n; i++)
        {
            if (!removed[i])
            {
                if (strcmp(s, SID[i]) == 0 || strcmp(s, name[i]) == 0)
                {
                    if (op)
                        printf("%d %s %d %s %d %d %d %d %.2f\n", rank(i), SID[i], CID[i], name[i], score[i][0], score[i][1], score[i][2], score[i][3], score[i][4] / 4.0 + EPS);
                    else
                    {
                        removed[i] = 1;
                        n--;
                        r++;
                    }
                }
            }
        }

        if (!op)
        {
            printf("%d student(s) removed.\n", r);
        }
    }
}

void show_ranking()
{
    printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n\n");
}

int rank(int i)
{
    int current = score[i][4];
    int res = 0;
    for (int j = 0; j < n; j++)
    {
        if (i == j)
            continue;

        if (score[j][4] >= current && !removed[j])
        {
            res++;
        }
    }

    return res + 1;
}

int pass(int score)
{
    return score >= 60 ? 1 : 0;
}

void show_statistics_detail(int class)
{
    int chinese = 0, math = 0, english = 0, programming = 0;
    int p_c = 0, p_m = 0, p_e = 0, p_p = 0;
    int p0 = 0, p1 = 0, p2 = 0, p3 = 0, pa = 0;
    int total = 0, nums = 0;

    for (int i = 0; i < maxn; i++)
    {
        if (CID[i] == 0)
            break;

        if (CID[i] == class || class == 0)
        {
            nums++;
            int pn = 0;

            chinese += score[i][0];
            if (pass(score[i][0]))
            {
                p_c++;
                pn++;
            }
            math += score[i][1];
            if (pass(score[i][1]))
            {
                p_m++;
                pn++;
            }
            english += score[i][2];
            if (pass(score[i][2]))
            {
                p_e++;
                pn++;
            }
            programming += score[i][3];
            if (pass(score[i][3]))
            {
                p_p++;
                pn++;
            }

            switch (pn)
            {
            case 0:
                p0++;
                break;
            case 1:
                p1++;
                break;
            case 2:
                p2++;
                break;
            case 3:
                p3++;
                break;
            case 4:
                pa++;
                break;
            }

            total = chinese + math + english + programming;
        }
    }

    puts("Chinese");
    printf("Average Score: %.2f\n", (float)chinese / nums);
    printf("Number of passed students: %d\n", p_c);
    printf("Number of failed students: %d\n", nums - p_c);
    puts("");

    puts("Mathematics");
    printf("Average Score: %.2f\n", (float)math / nums);
    printf("Number of passed students: %d\n", p_m);
    printf("Number of failed students: %d\n", nums - p_m);
    puts("");

    puts("English");
    printf("Average Score: %.2f\n", (float)english / nums);
    printf("Number of passed students: %d\n", p_e);
    printf("Number of failed students: %d\n", nums - p_e);
    puts("");

    puts("Programming");
    printf("Average Score: %.2f\n", (float)programming / nums);
    printf("Number of passed students: %d\n", p_p);
    printf("Number of failed students: %d\n", nums - p_p);
    puts("");

    puts("Overall:");
    printf("Numbers of students who passed all subjects: %d\n", pa);
    printf("Numbers of students who passed 3 or more subjects: %d\n", p3);
    printf("Numbers of students who passed 2 or more subjects: %d\n", p2);
    printf("Numbers of students who passed 1 or more subjects: %d\n", p1);
    printf("Numbers of students who passed failed all subjects: %d\n", p0);
    puts("");
}

void show_statistics()
{
    int class;
    printf("Please enter class ID, 0 for the whole statistics.\n");
    scanf("%d", &class);

    show_statistics_detail(class);
}

void print_menu()
{
    printf("Welcome to Student Performance Management System (SPMS).\n");
    printf("\n");
    printf("1 - Add\n");
    printf("2 - Remove\n");
    printf("3 - Query\n");
    printf("4 - Show ranking\n");
    printf("5 - Show Statistics\n");
    printf("0 - Exit\n");
    printf("\n");
}
