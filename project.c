#define VAT_RATE 0.05

int g_job_no, g_warranty_days;
double g_parts_cost, g_labour_cost;

void banner(void)
{
    printf("\nMOBILE REPAIR SHOP\n");
    printf("JOB CARD\n\n");
}

void menu(void)
{
    printf("1. Enter Job Details\n");
    printf("2. Calculate Bill\n");
    printf("3. Exit\n\n");
}

void read_job(void)
{
    printf("Enter Job No\t\t:\t");
    scanf("%d", &g_job_no);

    printf("Enter Warranty Days\t:\t");
    scanf("%d", &g_warranty_days);

    printf("Enter Parts Cost\t:\t");
    scanf("%lf", &g_parts_cost);

    printf("Enter Labour Cost\t:\t");
    scanf("%lf", &g_labour_cost);
}

double calculate_subtotal(double parts, double labour)
{
    return parts + labour;
}

double calculate_vat(double subtotal)
{
    return subtotal * VAT_RATE;
}

void print_job(double subtotal, double vat, double total)
{
    printf("\nJOB NO\t\t:\t%d\n", g_job_no);
    printf("WARRANTY\t:\t%d days\n", g_warranty_days);
    printf("SUBTOTAL\t:\t%.2f\n", subtotal);
    printf("VAT\t\t:\t%.2f\n", vat);
    printf("TOTAL\t\t:\t%.2f\n", total);
}

int main(void)
{
    double subtotal, vat, total;

    banner();
    menu();
    read_job();

    subtotal = calculate_subtotal(g_parts_cost, g_labour_cost);
    vat = calculate_vat(subtotal);
    total = subtotal + vat;

    print_job(subtotal, vat, total);

    return 0;
}
