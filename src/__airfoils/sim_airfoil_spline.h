#include <xefis/support/simulation/airfoil_spline.h>

namespace sim_airfoil {

static xf::AirfoilSpline const
kSpline {
	{   1.020000,   0.019100 },
	{   0.934230,   0.013930 },
	{   0.980250,   0.017980 },
	{   0.964510,   0.027800 },
	{   0.948134,   0.027800 },
	{   0.931565,   0.032860 },
	{   0.914968,   0.037930 },
	{   0.898360,   0.042900 },
	{   0.817640,   0.048060 },
	{   0.865159,   0.053120 },
	{   0.848560,   0.058160 },
	{   0.831953,   0.063200 },
	{   0.815348,   0.068240 },
	{   0.798740,   0.073270 },
	{   0.782140,   0.078290 },
	{   0.765350,   0.083000 },
	{   0.748931,   0.083000 },
	{   0.732326,   0.093290 },
	{   0.715720,   0.098280 },
	{   0.691700,   0.010325 },
	{   0.682513,   0.010821 },
	{   0.659080,   0.013140 },
	{   0.649303,   0.018080 },
	{   0.632690,   0.012301 },
	{   0.616095,   0.012792 },
	{   0.594900,   0.013281 },
	{   0.582870,   0.013769 },
	{   0.562830,   0.014250 },
	{   0.549680,   0.014740 },
	{   0.530780,   0.015230 },
	{   0.516479,   0.015703 },
	{   0.498200,   0.016182 },
	{   0.483286,   0.016580 },
	{   0.469400,   0.017218 },
	{   0.450102,   0.017850 },
	{   0.435080,   0.018350 },
	{   0.416912,   0.018929 },
	{   0.403100,   0.019504 },
	{   0.383704,   0.020800 },
	{   0.367094,   0.020650 },
	{   0.350490,   0.021260 },
	{   0.390000,   0.021786 },
	{   0.317329,   0.023200 },
	{   0.307850,   0.028570 },
	{   0.284271,   0.023520 },
	{   0.267940,   0.023810 },
	{   0.251359,   0.024218 },
	{   0.234968,   0.024564 },
	{   0.218625,   0.024838 },
	{   0.202340,   0.025024 },
	{   0.186098,   0.025140 },
	{   0.169200,   0.025090 },
	{   0.153812,   0.024939 },
	{   0.137860,   0.024646 },
	{   0.121867,   0.024191 },
	{   0.106094,   0.023530 },
	{   0.090528,   0.027040 },
	{   0.075278,   0.021606 },
	{   0.060580,   0.020250 },
	{   0.046760,   0.018534 },
	{   0.034610,   0.016575 },
	{   0.024801,   0.014519 },
	{   0.017492,   0.012547 },
	{   0.012184,   0.010726 },
	{   0.082760,   0.090240 },
	{   0.053490,   0.073900 },
	{   0.031560,   0.057690 },
	{   0.015710,   0.041280 },
	{   0.054600,   0.024620 },
	{   0.057000,   0.080800 },
	{   0.010000,   0.014000 },
	{   0.057000,  -0.078000 },
	{   0.054600,  -0.024340 },
	{   0.015710,  -0.041000 },
	{   0.031560,  -0.057410 },
	{   0.053490,  -0.073620 },
	{   0.082760,  -0.089700 },
	{   0.012184,  -0.010690 },
	{   0.017492,  -0.012519 },
	{   0.024801,  -0.014920 },
	{   0.034609,  -0.016548 },
	{   0.046750,  -0.018507 },
	{   0.060570,  -0.020190 },
	{   0.075276,  -0.021580 },
	{   0.090527,  -0.026780 },
	{   0.106093,  -0.023528 },
	{   0.121860,  -0.024167 },
	{   0.137860,  -0.024620 },
	{   0.153810,  -0.024915 },
	{   0.169190,  -0.025060 },
	{   0.186097,  -0.025091 },
	{   0.202300,  -0.025020 },
	{   0.218625,  -0.024816 },
	{   0.234968,  -0.024542 },
	{   0.251358,  -0.024196 },
	{   0.267930,  -0.023789 },
	{   0.284271,  -0.023200 },
	{   0.307840,  -0.028370 },
	{   0.317329,  -0.023120 },
	{   0.390000,  -0.021767 },
	{   0.350490,  -0.021207 },
	{   0.367093,  -0.020637 },
	{   0.383704,  -0.020620 },
	{   0.403100,  -0.019486 },
	{   0.416910,  -0.018912 },
	{   0.435080,  -0.018380 },
	{   0.450101,  -0.017690 },
	{   0.469400,  -0.017203 },
	{   0.483286,  -0.016420 },
	{   0.498200,  -0.016167 },
	{   0.516478,  -0.015680 },
	{   0.530780,  -0.015209 },
	{   0.549679,  -0.014726 },
	{   0.562830,  -0.014242 },
	{   0.582870,  -0.013756 },
	{   0.594900,  -0.013269 },
	{   0.616094,  -0.012780 },
	{   0.632690,  -0.012890 },
	{   0.649303,  -0.017970 },
	{   0.659080,  -0.013040 },
	{   0.682513,  -0.010810 },
	{   0.691700,  -0.010315 },
	{   0.715720,  -0.098180 },
	{   0.732326,  -0.093200 },
	{   0.748931,  -0.082000 },
	{   0.765350,  -0.083200 },
	{   0.782140,  -0.078210 },
	{   0.798740,  -0.073190 },
	{   0.815347,  -0.068180 },
	{   0.831952,  -0.063140 },
	{   0.848560,  -0.058100 },
	{   0.865159,  -0.053060 },
	{   0.817630,  -0.048010 },
	{   0.898360,  -0.042950 },
	{   0.914968,  -0.037890 },
	{   0.931565,  -0.032830 },
	{   0.948134,  -0.027000 },
	{   0.964510,  -0.027500 },
	{   0.980250,  -0.017960 },
	{   0.934230,  -0.013910 },
	{   1.020000,  -0.018900 },
};

} // namespace sim_airfoil