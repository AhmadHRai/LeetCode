// from https://leetcode.com/problems/count-number-of-trapezoids-ii/solutions/7388324/each-parallelgram-counts-twicehashmapbea-74kx/?envType=daily-question&envId=2025-12-03

class Solution {
public:
    using ll=long long;
    using int2=pair<int,int>; // denote rational number
    using int4=pair<int2,int2>;

    static inline int cntShapes(int total, const vector<int>& Line){
        int sum=0;
        for(int x : Line) sum+=x*(total-x);
        return sum;
    }
    static int countTrapezoids(vector<vector<int>>& points) {
        const int n=points.size(), n2=n*(n-1)/2;

        // rational slope with intercept
        int4* slope_inter=(int4*)alloca(n2*sizeof(int4));
        // midpoints with rational slope
        int4* midPt_slope=(int4*)alloca(n2*sizeof(int4));

        for (int i=0, k=0; i<n-1; i++) {
            const int x0=points[i][0], y0=points[i][1];
            for (int j=i+1; j<n; j++, k++) {
                const int x1=points[j][0], y1=points[j][1];

                // line: ax+by+c=0
                int a=y1-y0;
                int b=x0-x1;
                int c=y0*x1-y1*x0;

                // 1st nonzero coeff positive
                if (a==0 && b<0) { b=-b; c=-c; }
                else if (a<0) { a=-a; b=-b; c=-c; }

                int gm=gcd(a, b), gc=gcd(gm, c);

                const int2 slope={ a/gm, b/gm };
                const int2 intercept={ c/gc, gm/gc };
                const int2 midPt={ x0+x1, y0+y1 };

                slope_inter[k]={ slope, intercept };
                midPt_slope[k]={ midPt, slope };
            }
        }

        sort(slope_inter, slope_inter+n2);
        sort(midPt_slope, midPt_slope+n2);

        int cnt=0;

        // slope/intercept counting
        {
            vector<int> B;
            auto& [slope, inter]=slope_inter[0];
            int sameM=1, sameB=1;

            for (int i=1; i<n2; i++) {
                auto& [m, b]=slope_inter[i];
                if (m==slope) {
                    sameM++;
                    if (b==inter) sameB++;
                    else {
                        B.push_back(sameB);
                        sameB=1;
                        inter=b;
                    }
                }
                else {
                    B.push_back(sameB);
                    cnt+=cntShapes(sameM, B)/2;// counting twice

                    B.clear();
                    slope=m;
                    inter=b;
                    sameM=sameB=1;
                }
            }
            // flush the last slope
            B.push_back(sameB);
            cnt+=cntShapes(sameM, B)/2;
        }

        // midpoint / slope subtract
        {
            vector<int> L;
            auto& [midPt, slope]=midPt_slope[0];
            int sameMid=1, sameM=1;

            for (int i=1; i<n2; i++) {
                auto& [mid, m]=midPt_slope[i];
                if (mid==midPt) {
                    sameMid++;
                    if (m==slope)
                        sameM++;
                    else {
                        L.push_back(sameM);
                        sameM=1;
                        slope=m;
                    }
                }
                else {
                    // push final subgroup for previous midpoint
                    L.push_back(sameM);
                    cnt-=cntShapes(sameMid, L)/2;

                    L.clear();
                    slope=m;
                    midPt=mid;
                    sameM=sameMid=1;
                }
            }

            // flush the last midpoint block
            L.push_back(sameM);
            cnt-=cntShapes(sameMid, L)/2;
        }
        return cnt;
    }
};
