#include <stdint.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "../matrix/matrix.c"

static void test_create_matrix(void **state) {
    assert_true(create_matrix(0,0) == NULL);
    assert_true(create_matrix(1,0) == NULL);
    assert_true(create_matrix(0,1) == NULL);
    assert_true(create_matrix(100,0) == NULL);
    assert_true(create_matrix(0,100) == NULL);
    assert_true(create_matrix(54,31) == NULL);
    assert_true(create_matrix(73,80) == NULL);
    assert_true(create_matrix(-5,2) == NULL);
    assert_true(create_matrix(2,-5) == NULL);
    assert_true(create_matrix(-10,-9) == NULL);
}

static void test_fill_matrix(void **state) {
    Matrix* mat1 = create_matrix(2, 2);
    double values[] = {1.0, 2.0, 3.0, 4.0};
    fill_matrix(mat1, values);
    assert_true(mat1->value[0][0] == 1.0);
    assert_true(mat1->value[0][1] == 2.0);
    assert_true(mat1->value[1][0] == 3.0);
    assert_true(mat1->value[1][1] == 4.0);

    Matrix* mat2 = create_matrix(2, 2);
    double values2[] = {2.0, 2.0, 3.0, 3.0};
    fill_matrix(mat2, values2);
    assert_true(mat2->value[0][0] == 2.0);
    assert_true(mat2->value[0][1] == 2.0);
    assert_true(mat2->value[1][0] == 3.0);
    assert_true(mat2->value[1][1] == 3.0);

    Matrix* mat3 = create_matrix(2, 3);
    double values3[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    fill_matrix(mat3, values3);
    assert_true(mat3->value[0][0] == 1.0);
    assert_true(mat3->value[0][1] == 2.0);
    assert_true(mat3->value[0][2] == 3.0);
    assert_true(mat3->value[1][0] == 4.0);
    assert_true(mat3->value[1][1] == 5.0);
    assert_false(mat3->value[1][2] == 3.0);


    free(mat1);
    free(mat2);
    free(mat3);
}

static void test_print_matrix(void **state){
    Matrix* mat1 = create_matrix(2, 2);
    double values3[] = {1.0, 2.0, 3.0, 4.0};
    fill_matrix(mat1, values3);
    
    freopen("test_output.txt", "w", stdout);
    print_matrix(&mat1);
     // Close the file stream to revert to normal stdout
    fclose(stdout);
    // Open the file to read the captured output
    FILE* file = fopen("test_output.txt", "r");
    assert(file != NULL);
    // Check the printed output against your expectations
    char buffer[100];  // Adjust the size as needed
    fgets(buffer, sizeof(buffer), file);
    // Replace this assertion with your actual expected output
    assert(strcmp(buffer, "This is the content of this 2 x 2 matrix 1.000000 2.000000 \t3.000000 4.000000 \t") == 0);
    // Close the file 
    fclose(file);
    free(mat1);


}

int main(void) {
    int result = 0;
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_create_matrix),
        cmocka_unit_test(test_fill_matrix),
        cmocka_unit_test(test_print_matrix),
    };
    result |= cmocka_run_group_tests_name("matrix", tests, NULL, NULL);
    
    return result;  
}


