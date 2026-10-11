#include <stdio.h>

#define VAT_RATE 0.05

int main(void)
{
    int job_no;
    int warranty_days;
    double parts_cost, labour_cost;
    double subtotal, vat, total;

    printf("          MOBILE REPAIR SHOP\n");
    printf("              JOB CARD\n\n");

    printf("Enter Job No       \t:\t");
    scanf("%d", &job_no);

    printf("Enter Warranty Days\t:\t");
    scanf("%d", &warranty_days);

    printf("Enter Parts Cost   \t:\t");
    scanf("%lf", &parts_cost);

    printf("Enter Labour Cost  \t:\t");
    scanf("%lf", &labour_cost);

    subtotal = parts_cost + labour_cost;
    vat = subtotal * VAT_RATE;
    total = subtotal + vat;

    printf("\n");

    printf("JOB NO\t\t:\t%d\n", job_no);
    printf("WARRANTY\t:\t%d\n", warranty_days);
    printf("SUBTOTAL\t:\t%.2f\n", subtotal);
    printf("TOTAL\t\t:\t%.2f\n", total);

    printf("\n");

    printf("Parts Cost\t:\t%.2f\n", parts_cost);
    printf("Labour Cost\t:\t%.2f\n", labour_cost);
    printf("VAT\t\t:\t%.2f\n", vat);
    printf("Total Bill\t:\t%.2f\n", total);

    return 0;
}
