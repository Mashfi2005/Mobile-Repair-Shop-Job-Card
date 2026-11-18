#include <stdio.h>

#define VAT_RATE 0.05

int g_job_no, g_warranty_days, g_parts_qty;
double g_parts_price, g_labour_cost;

void banner(void)
{
    printf("\nMOBILE REPAIR SHOP\n");
    printf("JOB CARD SYSTEM\n");
}

void menu(void)
{
    printf("\n1. Add New Job\n");
    printf("2. Show Total Summary\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void read_job(void)
{
    printf("\nEnter Job No\t\t:\t");
    scanf("%d", &g_job_no);

    printf("Enter Warranty Days\t:\t");
    scanf("%d", &g_warranty_days);

    printf("Enter Parts Quantity\t:\t");
    scanf("%d", &g_parts_qty);

    if (g_parts_qty < 0) {
        printf("Quantity cannot be negative. Set to 0.\n");
        g_parts_qty = 0;
    }

    printf("Enter Unit Parts Price\t:\t");
    scanf("%lf", &g_parts_price);

    printf("Enter Labour Cost\t:\t");
    scanf("%lf", &g_labour_cost);
}

double calculate_subtotal(int qty, double price, double labour)
{
    return qty * price + labour;
}

double calculate_vat(double subtotal)
{
    return subtotal * VAT_RATE;
}

void print_job(double subtotal, double vat, double total)
{
    printf("\n JOB DETAILS \n");

    printf("JOB NO\t\t:\t%d\n", g_job_no);
    printf("WARRANTY\t:\t%d days\n", g_warranty_days);
    printf("PARTS QUANTITY\t:\t%d\n", g_parts_qty);
    printf("SUBTOTAL\t:\t%.2f\n", subtotal);
    printf("VAT\t\t:\t%.2f\n", vat);
    printf("TOTAL BILL\t:\t%.2f\n", total);
}

int main(void)
{
    int choice, count = 0;
    double subtotal, vat, total;
    double grand_total = 0.0;

    banner();

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                read_job();

                subtotal = calculate_subtotal(
                    g_parts_qty, g_parts_price, g_labour_cost);

                vat = calculate_vat(subtotal);
                total = subtotal + vat;

                print_job(subtotal, vat, total);

                grand_total += total;
                count++;

                break;

            case 2:
                printf("\n TOTAL SUMMARY \n");
                printf("Total Jobs\t:\t%d\n", count);
                printf("Grand Total\t:\t%.2f\n", grand_total);

                break;

            case 3:
                printf("\nThank you. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Choose 1, 2 or 3.\n");
        }

    } while (choice != 3);

    return 0;
}
