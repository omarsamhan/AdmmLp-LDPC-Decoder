#include "gtest/gtest.h"
#include "../../tools/read_parity_mat.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

typedef const int cint; // Constant int

cint n = 96; cint m = 48;
cint d_c = 3; cint d_v = 6;
cint col_density[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
                     3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
                     3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                     3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
                     3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
                     3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
                     3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
                     3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
                     
cint row_density[] = {6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 
                     6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 
                     6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 
                     6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};

cint var2chk[n][d_c] = {{10	,30,	40},
                      {5	,32,	45},
                      {16	,18,	39},
                      {12	,22,	38},
                      {15	,19,	47},
                      {2	,17,	34},
                      {9	,24,	42},
                      {1	,29,	33},
                      {4	,27,	36},
                      {3	,26,	35},
                      {11	,31,	43},
                      {7	,21,	44},
                      {8	,20,	48},
                      {14	,23,	46},
                      {6	,28,	37},
                      {13	,25,	41},
                      {14	,32,	43},
                      {5	,23,	37},
                      {2	,31,	36},
                      {1	,28,	34},
                      {7	,25,	47},
                      {10	,21,	33},
                      {15	,30,	35},
                      {16	,26,	48},
                      {3	,22,	46},
                      {12	,20,	41},
                      {8	,18,	38},
                      {4	,19,	45},
                      {6	,24,	40},
                      {9	,27,	39},
                      {13	,17,	42},
                      {11	,29,	44},
                      {8	,24,	34},
                      {6	,25,	36},
                      {9	,19,	43},
                      {1	,20,	46},
                      {14	,27,	42},
                      {7	,22,	39},
                      {13	,18,	35},
                      {4	,26,	40},
                      {16	,29,	38},
                      {15	,21,	48},
                      {11	,23,	45},
                      {3	,17,	47},
                      {5	,28,	44},
                      {12	,32,	33},
                      {2	,30,	41},
                      {10	,31,	37},
                      {10	,18,	36},
                      {4	,23,	44},
                      {9	,29,	40},
                      {2	,27,	38},
                      {8	,30,	42},
                      {12	,28,	43},
                      {11	,20,	37},
                      {1	,19,	35},
                      {15	,31,	39},
                      {16	,32,	41},
                      {5	,26,	33},
                      {3	,25,	45},
                      {13	,21,	34},
                      {14	,24,	48},
                      {7	,17,	46},
                      {6	,22,	47},
                      {7	,27,	40},
                      {11	,18,	33},
                      {2	,32,	35},
                      {10	,28,	47},
                      {5	,24,	41},
                      {12	,25,	37},
                      {3	,19,	39},
                      {14	,31,	44},
                      {16	,30,	34},
                      {13	,20,	38},
                      {9	,22,	36},
                      {6	,17,	45},
                      {4	,21,	42},
                      {15	,29,	46},
                      {8	,26,	43},
                      {1	,23,	48},
                      {1	,25,	42},
                      {15	,22,	40},
                      {8	,21,	41},
                      {9	,18,	47},
                      {6	,27,	43},
                      {11	,30,	46},
                      {7	,31,	35},
                      {5	,20,	36},
                      {14	,17,	38},
                      {16	,28,	45},
                      {4	,32,	37},
                      {13	,23,	33},
                      {12	,26,	44},
                      {3	,29,	48},
                      {2	,24,	39},
                      {10	,19,	34}};

cint chk2var[m][d_v] = {{8	,20	,36	,56	,80	,81},
                        {6	,19	,47	,52	,67	,95},
                        {10	,25	,44	,60	,71	,94},
                        {9	,28	,40	,50	,77	,91},
                        {2	,18	,45	,59	,69	,88},
                        {15	,29	,34	,64	,76	,85},
                        {12	,21	,38	,63	,65	,87},
                        {13	,27	,33	,53	,79	,83},
                        {7	,30	,35	,51	,75	,84},
                        {1	,22	,48	,49	,68	,96},
                        {11	,32	,43	,55	,66	,86},
                        {4	,26	,46	,54	,70	,93},
                        {16	,31	,39	,61	,74	,92},
                        {14	,17	,37	,62	,72	,89},
                        {5	,23	,42	,57	,78	,82},
                        {3	,24	,41	,58	,73	,90},
                        {6	,31	,44	,63	,76	,89},
                        {3	,27	,39	,49	,66	,84},
                        {5	,28	,35	,56	,71	,96},
                        {13	,26	,36	,55	,74	,88},
                        {12	,22	,42	,61	,77	,83},
                        {4	,25	,38	,64	,75	,82},
                        {14	,18	,43	,50	,80	,92},
                        {7	,29	,33	,62	,69	,95},
                        {16	,21	,34	,60	,70	,81},
                        {10	,24	,40	,59	,79	,93},
                        {9	,30	,37	,52	,65	,85},
                        {15	,20	,45	,54	,68	,90},
                        {8	,32	,41	,51	,78	,94},
                        {1	,23	,47	,53	,73	,86},
                        {11	,19	,48	,57	,72	,87},
                        {2	,17	,46	,58	,67	,91},
                        {8	,22	,46	,59	,66	,92},
                        {6	,20	,33	,61	,73	,96},
                        {10	,23	,39	,56	,67	,87},
                        {9	,19	,34	,49	,75	,88},
                        {15	,18	,48	,55	,70	,91},
                        {4	,27	,41	,52	,74	,89},
                        {3	,30	,38	,57	,71	,95},
                        {1	,29	,40	,51	,65	,82},
                        {16	,26	,47	,58	,69	,83},
                        {7	,31	,37	,53	,77	,81},
                        {11	,17	,35	,54	,79	,85},
                        {12	,32	,45	,50	,72	,93},
                        {2	,28	,43	,60	,76	,90},
                        {14	,25	,36	,63	,78	,86},
                        {5	,21	,44	,64	,68	,84},
                        {13	,24	,42	,62	,80	,94}};
                            
TEST(read_valid_file, read_alist_file) {

    static string code_filename = "../../../code_files/96.3.963";
    auto cr = read_alist(code_filename);

    ASSERT_EQ(cr.n, n);
    ASSERT_EQ(cr.m, m);
    ASSERT_EQ(cr.d_c, d_c);
    ASSERT_EQ(cr.d_v, d_v);

    for(int i = 0; i < n; i++) ASSERT_EQ(cr.col_density[i], col_density[i]);

    for(int i = 0; i < m; i++) ASSERT_EQ(cr.row_density[i], row_density[i]);


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < d_c; j++) 
            ASSERT_EQ(cr.var2chk_conn[i][j], var2chk[i][j]);
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < d_v; j++) 
            ASSERT_EQ(cr.chk2var_conn[i][j], chk2var[i][j]);
    }
}
