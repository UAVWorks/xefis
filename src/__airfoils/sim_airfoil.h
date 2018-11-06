#include <xefis/utility/field.h>

namespace sim_airfoil {

static xf::Field<double, si::Angle, double> const
kLiftField {
	{
		31000.0,
		{
			{  -10.000_deg,  -0.7399 },
			{   -9.000_deg,  -0.7105 },
			{   -8.000_deg,  -0.6794 },
			{   -7.000_deg,  -0.6291 },
			{   -5.000_deg,  -0.5710 },
			{   -4.000_deg,  -0.4594 },
			{   -3.000_deg,  -0.3746 },
			{   -2.000_deg,  -0.2091 },
			{   -1.000_deg,  -0.1048 },
			{    0.000_deg,   0.0001 },
			{    1.000_deg,   0.1050 },
			{    2.000_deg,   0.2092 },
			{    3.000_deg,   0.3747 },
			{    4.000_deg,   0.4596 },
			{    5.000_deg,   0.5711 },
			{    6.000_deg,   0.6681 },
			{    7.000_deg,   0.6307 },
			{   11.000_deg,   0.7514 },
			{   12.000_deg,   0.7672 },
			{   18.000_deg,   0.9247 },
			{   19.000_deg,   0.9591 },
			{   20.000_deg,   0.9886 },
			{   21.000_deg,   1.0208 },
			{   22.000_deg,   1.0540 },
			{   23.000_deg,   1.0861 },
			{   24.000_deg,   1.1173 },
			{   25.000_deg,   1.1481 },
			{   26.000_deg,   1.1785 },
			{   27.000_deg,   1.2082 },
			{   28.000_deg,   1.2367 },
		},
	},
	{
		51000.0,
		{
			{  -10.000_deg,  -0.5331 },
			{   -9.000_deg,  -0.7381 },
			{   -8.000_deg,  -0.7167 },
			{   -5.000_deg,  -0.5553 },
			{   -4.000_deg,  -0.4440 },
			{   -3.000_deg,  -0.3441 },
			{   -2.000_deg,  -0.2113 },
			{   -1.000_deg,  -0.1058 },
			{    0.000_deg,   0.0001 },
			{    1.000_deg,   0.1060 },
			{    2.000_deg,   0.2114 },
			{    3.000_deg,   0.3442 },
			{    4.000_deg,   0.4442 },
			{    5.000_deg,   0.5555 },
			{   12.000_deg,   0.7769 },
			{   13.000_deg,   0.7944 },
			{   14.000_deg,   0.8109 },
			{   15.000_deg,   0.8347 },
			{   16.000_deg,   0.8665 },
			{   17.000_deg,   0.8931 },
			{   18.000_deg,   0.9229 },
			{   19.000_deg,   0.9549 },
			{   20.000_deg,   0.9874 },
			{   21.000_deg,   1.0201 },
			{   22.000_deg,   1.0528 },
			{   23.000_deg,   1.0851 },
			{   24.000_deg,   1.1170 },
			{   25.000_deg,   1.1488 },
			{   26.000_deg,   1.1796 },
			{   27.000_deg,   1.2093 },
			{   28.000_deg,   1.2386 },
			{   29.000_deg,   1.2656 },
			{   30.000_deg,   1.2923 },
		},
	},
	{
		71000.0,
		{
			{   -5.000_deg,  -0.5498 },
			{   -4.000_deg,  -0.4397 },
			{   -3.000_deg,  -0.3376 },
			{   -2.000_deg,  -0.2127 },
			{   -1.000_deg,  -0.1065 },
			{    0.000_deg,   0.0001 },
			{    1.000_deg,   0.1067 },
			{    2.000_deg,   0.2129 },
			{    3.000_deg,   0.3378 },
			{    4.000_deg,   0.4399 },
			{    5.000_deg,   0.5499 },
			{    7.000_deg,   0.7130 },
			{    8.000_deg,   0.7301 },
			{   15.000_deg,   0.8380 },
			{   16.000_deg,   0.8630 },
			{   17.000_deg,   0.8920 },
			{   18.000_deg,   0.9232 },
			{   19.000_deg,   0.9553 },
			{   20.000_deg,   0.9880 },
			{   21.000_deg,   1.0210 },
			{   22.000_deg,   1.0536 },
			{   23.000_deg,   1.0860 },
			{   24.000_deg,   1.1177 },
			{   25.000_deg,   1.1500 },
		},
	},
	{
		91000.0,
		{
			{   -5.000_deg,  -0.5481 },
			{   -4.000_deg,  -0.4382 },
			{   -3.000_deg,  -0.3350 },
			{   -2.000_deg,  -0.2137 },
			{   -1.000_deg,  -0.1070 },
			{    0.000_deg,   0.0001 },
			{    1.000_deg,   0.1071 },
			{    2.000_deg,   0.2138 },
			{    3.000_deg,   0.3351 },
			{    4.000_deg,   0.4384 },
			{    5.000_deg,   0.5482 },
			{   14.000_deg,   0.8110 },
			{   15.000_deg,   0.8371 },
			{   16.000_deg,   0.8660 },
			{   17.000_deg,   0.8937 },
			{   18.000_deg,   0.9239 },
			{   19.000_deg,   0.9559 },
			{   20.000_deg,   0.9886 },
		},
	},
	{
		111000.0,
		{
			{   -6.000_deg,  -0.6502 },
			{   -5.000_deg,  -0.5467 },
			{   -4.000_deg,  -0.4376 },
			{   -3.000_deg,  -0.3333 },
			{   -2.000_deg,  -0.2144 },
			{   -1.000_deg,  -0.1074 },
			{    0.000_deg,   0.0001 },
			{    1.000_deg,   0.1075 },
			{    2.000_deg,   0.2146 },
			{    3.000_deg,   0.3334 },
			{    4.000_deg,   0.4378 },
			{    5.000_deg,   0.5469 },
			{    9.000_deg,   0.7405 },
			{   14.000_deg,   0.8119 },
			{   15.000_deg,   0.8380 },
			{   16.000_deg,   0.8639 },
			{   17.000_deg,   0.8933 },
			{   18.000_deg,   0.9244 },
			{   19.000_deg,   0.9565 },
			{   20.000_deg,   0.9894 },
			{   21.000_deg,   1.0223 },
		},
	},
	{
		131000.0,
		{
			{   -5.000_deg,  -0.5456 },
			{   -4.000_deg,  -0.4375 },
			{   -3.000_deg,  -0.3322 },
			{   -2.000_deg,  -0.2298 },
			{   -1.000_deg,  -0.1077 },
			{    0.000_deg,   0.0001 },
			{    1.000_deg,   0.1078 },
			{    2.000_deg,   0.2304 },
			{    3.000_deg,   0.3323 },
			{    4.000_deg,   0.4376 },
			{    6.000_deg,   0.6499 },
			{   14.000_deg,   0.8114 },
			{   15.000_deg,   0.8364 },
			{   16.000_deg,   0.8656 },
			{   17.000_deg,   0.8944 },
			{   18.000_deg,   0.9252 },
			{   19.000_deg,   0.9571 },
			{   20.000_deg,   0.9898 },
			{   21.000_deg,   1.0230 },
			{   23.000_deg,   1.0886 },
			{   24.000_deg,   1.1197 },
			{   25.000_deg,   1.1523 },
			{   26.000_deg,   1.1835 },
			{   27.000_deg,   1.2130 },
			{   28.000_deg,   1.2432 },
			{   29.000_deg,   1.2706 },
		},
	},
	{
		151000.0,
		{
			{   -5.000_deg,  -0.5455 },
			{   -4.000_deg,  -0.4377 },
			{   -3.000_deg,  -0.3315 },
			{   -2.000_deg,  -0.2384 },
			{   -1.000_deg,  -0.1079 },
			{    0.000_deg,   0.0001 },
			{    1.000_deg,   0.1081 },
			{    2.000_deg,   0.2385 },
			{    3.000_deg,   0.3316 },
			{    4.000_deg,   0.4378 },
			{   11.000_deg,   0.7605 },
			{   12.000_deg,   0.7736 },
			{   13.000_deg,   0.7908 },
			{   14.000_deg,   0.8122 },
			{   15.000_deg,   0.8370 },
			{   16.000_deg,   0.8658 },
		},
	},
	{
		171000.0,
		{
			{   -8.000_deg,  -0.7458 },
			{   -7.000_deg,  -0.7177 },
			{   -5.000_deg,  -0.5452 },
			{   -4.000_deg,  -0.4379 },
			{   -3.000_deg,  -0.3310 },
			{   -2.000_deg,  -0.2323 },
			{   -1.000_deg,  -0.1081 },
			{    0.000_deg,   0.0001 },
			{    1.000_deg,   0.1083 },
			{    2.000_deg,   0.2324 },
			{    3.000_deg,   0.3311 },
			{    4.000_deg,   0.4381 },
			{    5.000_deg,   0.5454 },
			{    6.000_deg,   0.6506 },
			{   22.000_deg,   1.0570 },
			{   23.000_deg,   1.0892 },
			{   24.000_deg,   1.1211 },
			{   25.000_deg,   1.1535 },
		},
	},
};

static xf::Field<double, si::Angle, double> const
kDragField {
	{
		31000.0,
		{
			{  -10.000_deg,   0.1438 },
			{   -9.000_deg,   0.1266 },
			{   -8.000_deg,   0.1103 },
			{   -7.000_deg,   0.0931 },
			{   -5.000_deg,   0.0442 },
			{   -4.000_deg,   0.0308 },
			{   -3.000_deg,   0.0214 },
			{   -2.000_deg,   0.0175 },
			{   -1.000_deg,   0.0172 },
			{    0.000_deg,   0.0171 },
			{    1.000_deg,   0.0172 },
			{    2.000_deg,   0.0175 },
			{    3.000_deg,   0.0214 },
			{    4.000_deg,   0.0308 },
			{    5.000_deg,   0.0442 },
			{    6.000_deg,   0.0695 },
			{    7.000_deg,   0.0932 },
			{   11.000_deg,   0.1578 },
			{   12.000_deg,   0.1721 },
			{   18.000_deg,   0.2582 },
			{   19.000_deg,   0.2748 },
			{   20.000_deg,   0.2860 },
			{   21.000_deg,   0.2992 },
			{   22.000_deg,   0.3145 },
			{   23.000_deg,   0.3288 },
			{   24.000_deg,   0.3410 },
			{   25.000_deg,   0.3529 },
			{   26.000_deg,   0.3637 },
			{   27.000_deg,   0.3748 },
			{   28.000_deg,   0.3871 },
		},
	},
	{
		51000.0,
		{
			{  -10.000_deg,   0.1122 },
			{   -9.000_deg,   0.1230 },
			{   -8.000_deg,   0.1067 },
			{   -5.000_deg,   0.0344 },
			{   -4.000_deg,   0.0241 },
			{   -3.000_deg,   0.0171 },
			{   -2.000_deg,   0.0137 },
			{   -1.000_deg,   0.0134 },
			{    0.000_deg,   0.0133 },
			{    1.000_deg,   0.0134 },
			{    2.000_deg,   0.0137 },
			{    3.000_deg,   0.0171 },
			{    4.000_deg,   0.0241 },
			{    5.000_deg,   0.0344 },
			{   12.000_deg,   0.1689 },
			{   13.000_deg,   0.1840 },
			{   14.000_deg,   0.1973 },
			{   15.000_deg,   0.2116 },
			{   16.000_deg,   0.2281 },
			{   17.000_deg,   0.2411 },
			{   18.000_deg,   0.2545 },
			{   19.000_deg,   0.2684 },
			{   20.000_deg,   0.2823 },
			{   21.000_deg,   0.2961 },
			{   22.000_deg,   0.3097 },
			{   23.000_deg,   0.3236 },
			{   24.000_deg,   0.3381 },
			{   25.000_deg,   0.3488 },
			{   26.000_deg,   0.3612 },
			{   27.000_deg,   0.3735 },
			{   28.000_deg,   0.3843 },
			{   29.000_deg,   0.3965 },
			{   30.000_deg,   0.4072 },
		},
	},
	{
		71000.0,
		{
			{   -5.000_deg,   0.0292 },
			{   -4.000_deg,   0.0208 },
			{   -3.000_deg,   0.0149 },
			{   -2.000_deg,   0.0116 },
			{   -1.000_deg,   0.0113 },
			{    0.000_deg,   0.0112 },
			{    1.000_deg,   0.0113 },
			{    2.000_deg,   0.0116 },
			{    3.000_deg,   0.0149 },
			{    4.000_deg,   0.0208 },
			{    5.000_deg,   0.0293 },
			{    7.000_deg,   0.0860 },
			{    8.000_deg,   0.1025 },
			{   15.000_deg,   0.2109 },
			{   16.000_deg,   0.2246 },
			{   17.000_deg,   0.2387 },
			{   18.000_deg,   0.2531 },
			{   19.000_deg,   0.2676 },
			{   20.000_deg,   0.2820 },
			{   21.000_deg,   0.2967 },
			{   22.000_deg,   0.3089 },
			{   23.000_deg,   0.3228 },
			{   24.000_deg,   0.3364 },
			{   25.000_deg,   0.3484 },
		},
	},
	{
		91000.0,
		{
			{   -5.000_deg,   0.0264 },
			{   -4.000_deg,   0.0187 },
			{   -3.000_deg,   0.0134 },
			{   -2.000_deg,   0.0102 },
			{   -1.000_deg,   0.0100 },
			{    0.000_deg,   0.0099 },
			{    1.000_deg,   0.0100 },
			{    2.000_deg,   0.0102 },
			{    3.000_deg,   0.0134 },
			{    4.000_deg,   0.0187 },
			{    5.000_deg,   0.0264 },
			{   14.000_deg,   0.1935 },
			{   15.000_deg,   0.2088 },
			{   16.000_deg,   0.2247 },
			{   17.000_deg,   0.2383 },
			{   18.000_deg,   0.2523 },
			{   19.000_deg,   0.2666 },
			{   20.000_deg,   0.2809 },
		},
	},
	{
		111000.0,
		{
			{   -6.000_deg,   0.0415 },
			{   -5.000_deg,   0.0240 },
			{   -4.000_deg,   0.0172 },
			{   -3.000_deg,   0.0124 },
			{   -2.000_deg,   0.0093 },
			{   -1.000_deg,   0.0091 },
			{    0.000_deg,   0.0090 },
			{    1.000_deg,   0.0091 },
			{    2.000_deg,   0.0093 },
			{    3.000_deg,   0.0124 },
			{    4.000_deg,   0.0173 },
			{    5.000_deg,   0.0240 },
			{    9.000_deg,   0.1132 },
			{   14.000_deg,   0.1926 },
			{   15.000_deg,   0.2080 },
			{   16.000_deg,   0.2226 },
			{   17.000_deg,   0.2374 },
			{   18.000_deg,   0.2520 },
			{   19.000_deg,   0.2667 },
			{   20.000_deg,   0.2806 },
			{   21.000_deg,   0.2948 },
		},
	},
	{
		131000.0,
		{
			{   -5.000_deg,   0.0221 },
			{   -4.000_deg,   0.0162 },
			{   -3.000_deg,   0.0117 },
			{   -2.000_deg,   0.0086 },
			{   -1.000_deg,   0.0083 },
			{    0.000_deg,   0.0083 },
			{    1.000_deg,   0.0083 },
			{    2.000_deg,   0.0086 },
			{    3.000_deg,   0.0117 },
			{    4.000_deg,   0.0162 },
			{    6.000_deg,   0.0361 },
			{   14.000_deg,   0.1920 },
			{   15.000_deg,   0.2073 },
			{   16.000_deg,   0.2228 },
			{   17.000_deg,   0.2371 },
			{   18.000_deg,   0.2516 },
			{   19.000_deg,   0.2663 },
			{   20.000_deg,   0.2805 },
			{   21.000_deg,   0.2948 },
			{   23.000_deg,   0.3225 },
			{   24.000_deg,   0.3360 },
			{   25.000_deg,   0.3489 },
			{   26.000_deg,   0.3608 },
			{   27.000_deg,   0.3729 },
			{   28.000_deg,   0.3844 },
			{   29.000_deg,   0.3958 },
		},
	},
	{
		151000.0,
		{
			{   -5.000_deg,   0.0207 },
			{   -4.000_deg,   0.0152 },
			{   -3.000_deg,   0.0112 },
			{   -2.000_deg,   0.0083 },
			{   -1.000_deg,   0.0078 },
			{    0.000_deg,   0.0077 },
			{    1.000_deg,   0.0078 },
			{    2.000_deg,   0.0083 },
			{    3.000_deg,   0.0112 },
			{    4.000_deg,   0.0152 },
			{   11.000_deg,   0.1438 },
			{   12.000_deg,   0.1600 },
			{   13.000_deg,   0.1759 },
			{   14.000_deg,   0.1915 },
			{   15.000_deg,   0.2069 },
			{   16.000_deg,   0.2223 },
		},
	},
	{
		171000.0,
		{
			{   -8.000_deg,   0.0913 },
			{   -7.000_deg,   0.0671 },
			{   -5.000_deg,   0.0196 },
			{   -4.000_deg,   0.0145 },
			{   -3.000_deg,   0.0108 },
			{   -2.000_deg,   0.0081 },
			{   -1.000_deg,   0.0073 },
			{    0.000_deg,   0.0073 },
			{    1.000_deg,   0.0073 },
			{    2.000_deg,   0.0081 },
			{    3.000_deg,   0.0108 },
			{    4.000_deg,   0.0145 },
			{    5.000_deg,   0.0196 },
			{    6.000_deg,   0.0311 },
			{   22.000_deg,   0.3090 },
			{   23.000_deg,   0.3224 },
			{   24.000_deg,   0.3363 },
			{   25.000_deg,   0.3491 },
		},
	},
};

static xf::Field<double, si::Angle, double> const
kPitchingMomentField {
	{
		31000.0,
		{
			{  -10.000_deg,   0.0677 },
			{   -9.000_deg,   0.0689 },
			{   -8.000_deg,   0.0723 },
			{   -7.000_deg,   0.0786 },
			{   -5.000_deg,  -0.0035 },
			{   -4.000_deg,  -0.0052 },
			{   -3.000_deg,   0.0073 },
			{   -2.000_deg,  -0.0019 },
			{   -1.000_deg,  -0.0011 },
			{    0.000_deg,   0.0000 },
			{    1.000_deg,   0.0011 },
			{    2.000_deg,   0.0019 },
			{    3.000_deg,  -0.0073 },
			{    4.000_deg,   0.0051 },
			{    5.000_deg,   0.0035 },
			{    6.000_deg,  -0.0180 },
			{    7.000_deg,  -0.0788 },
			{   11.000_deg,  -0.0688 },
			{   12.000_deg,  -0.0713 },
			{   18.000_deg,  -0.1043 },
			{   19.000_deg,  -0.1109 },
			{   20.000_deg,  -0.1202 },
			{   21.000_deg,  -0.1288 },
			{   22.000_deg,  -0.1368 },
			{   23.000_deg,  -0.1456 },
			{   24.000_deg,  -0.1554 },
			{   25.000_deg,  -0.1653 },
			{   26.000_deg,  -0.1758 },
			{   27.000_deg,  -0.1863 },
			{   28.000_deg,  -0.1963 },
		},
	},
	{
		51000.0,
		{
			{  -10.000_deg,   0.0312 },
			{   -9.000_deg,   0.0517 },
			{   -8.000_deg,   0.0505 },
			{   -5.000_deg,  -0.0082 },
			{   -4.000_deg,  -0.0071 },
			{   -3.000_deg,  -0.0021 },
			{   -2.000_deg,  -0.0020 },
			{   -1.000_deg,  -0.0011 },
			{    0.000_deg,   0.0000 },
			{    1.000_deg,   0.0011 },
			{    2.000_deg,   0.0020 },
			{    3.000_deg,   0.0021 },
			{    4.000_deg,   0.0071 },
			{    5.000_deg,   0.0082 },
			{   12.000_deg,  -0.0640 },
			{   13.000_deg,  -0.0692 },
			{   14.000_deg,  -0.0760 },
			{   15.000_deg,  -0.0827 },
			{   16.000_deg,  -0.0880 },
			{   17.000_deg,  -0.0964 },
			{   18.000_deg,  -0.1048 },
			{   19.000_deg,  -0.1130 },
			{   20.000_deg,  -0.1215 },
			{   21.000_deg,  -0.1304 },
			{   22.000_deg,  -0.1395 },
			{   23.000_deg,  -0.1485 },
			{   24.000_deg,  -0.1572 },
			{   25.000_deg,  -0.1682 },
			{   26.000_deg,  -0.1782 },
			{   27.000_deg,  -0.1879 },
			{   28.000_deg,  -0.1989 },
			{   29.000_deg,  -0.2088 },
			{   30.000_deg,  -0.2201 },
		},
	},
	{
		71000.0,
		{
			{   -5.000_deg,  -0.0082 },
			{   -4.000_deg,  -0.0065 },
			{   -3.000_deg,  -0.0034 },
			{   -2.000_deg,  -0.0020 },
			{   -1.000_deg,  -0.0011 },
			{    0.000_deg,   0.0000 },
			{    1.000_deg,   0.0011 },
			{    2.000_deg,   0.0020 },
			{    3.000_deg,   0.0034 },
			{    4.000_deg,   0.0065 },
			{    5.000_deg,   0.0082 },
			{    7.000_deg,  -0.0331 },
			{    8.000_deg,  -0.0413 },
			{   15.000_deg,  -0.0814 },
			{   16.000_deg,  -0.0897 },
			{   17.000_deg,  -0.0978 },
			{   18.000_deg,  -0.1057 },
			{   19.000_deg,  -0.1137 },
			{   20.000_deg,  -0.1219 },
			{   21.000_deg,  -0.1301 },
			{   22.000_deg,  -0.1407 },
			{   23.000_deg,  -0.1499 },
			{   24.000_deg,  -0.1589 },
			{   25.000_deg,  -0.1696 },
		},
	},
	{
		91000.0,
		{
			{   -5.000_deg,  -0.0076 },
			{   -4.000_deg,  -0.0058 },
			{   -3.000_deg,  -0.0037 },
			{   -2.000_deg,  -0.0020 },
			{   -1.000_deg,  -0.0011 },
			{    0.000_deg,   0.0000 },
			{    1.000_deg,   0.0011 },
			{    2.000_deg,   0.0020 },
			{    3.000_deg,   0.0037 },
			{    4.000_deg,   0.0058 },
			{    5.000_deg,   0.0076 },
			{   14.000_deg,  -0.0763 },
			{   15.000_deg,  -0.0823 },
			{   16.000_deg,  -0.0886 },
			{   17.000_deg,  -0.0974 },
			{   18.000_deg,  -0.1063 },
			{   19.000_deg,  -0.1148 },
			{   20.000_deg,  -0.1234 },
		},
	},
	{
		111000.0,
		{
			{   -6.000_deg,  -0.0070 },
			{   -5.000_deg,  -0.0070 },
			{   -4.000_deg,  -0.0052 },
			{   -3.000_deg,  -0.0038 },
			{   -2.000_deg,  -0.0020 },
			{   -1.000_deg,  -0.0011 },
			{    0.000_deg,   0.0000 },
			{    1.000_deg,   0.0011 },
			{    2.000_deg,   0.0020 },
			{    3.000_deg,   0.0038 },
			{    4.000_deg,   0.0052 },
			{    5.000_deg,   0.0070 },
			{    9.000_deg,  -0.0448 },
			{   14.000_deg,  -0.0765 },
			{   15.000_deg,  -0.0825 },
			{   16.000_deg,  -0.0909 },
			{   17.000_deg,  -0.0991 },
			{   18.000_deg,  -0.1071 },
			{   19.000_deg,  -0.1147 },
			{   20.000_deg,  -0.1238 },
			{   21.000_deg,  -0.1330 },
		},
	},
	{
		131000.0,
		{
			{   -5.000_deg,  -0.0064 },
			{   -4.000_deg,  -0.0047 },
			{   -3.000_deg,  -0.0037 },
			{   -2.000_deg,   0.0010 },
			{   -1.000_deg,  -0.0010 },
			{    0.000_deg,   0.0000 },
			{    1.000_deg,   0.0010 },
			{    2.000_deg,  -0.0011 },
			{    3.000_deg,   0.0037 },
			{    4.000_deg,   0.0047 },
			{    6.000_deg,   0.0075 },
			{   14.000_deg,  -0.0775 },
			{   15.000_deg,  -0.0842 },
			{   16.000_deg,  -0.0901 },
			{   17.000_deg,  -0.0988 },
			{   18.000_deg,  -0.1075 },
			{   19.000_deg,  -0.1157 },
			{   20.000_deg,  -0.1240 },
			{   21.000_deg,  -0.1335 },
			{   23.000_deg,  -0.1520 },
			{   24.000_deg,  -0.1610 },
			{   25.000_deg,  -0.1714 },
			{   26.000_deg,  -0.1815 },
			{   27.000_deg,  -0.1915 },
			{   28.000_deg,  -0.2023 },
			{   29.000_deg,  -0.2127 },
		},
	},
	{
		151000.0,
		{
			{   -5.000_deg,  -0.0060 },
			{   -4.000_deg,  -0.0044 },
			{   -3.000_deg,  -0.0036 },
			{   -2.000_deg,   0.0016 },
			{   -1.000_deg,  -0.0010 },
			{    0.000_deg,   0.0000 },
			{    1.000_deg,   0.0010 },
			{    2.000_deg,  -0.0015 },
			{    3.000_deg,   0.0036 },
			{    4.000_deg,   0.0044 },
			{   11.000_deg,  -0.0584 },
			{   12.000_deg,  -0.0648 },
			{   13.000_deg,  -0.0712 },
			{   14.000_deg,  -0.0778 },
			{   15.000_deg,  -0.0847 },
			{   16.000_deg,  -0.0906 },
		},
	},
	{
		171000.0,
		{
			{   -8.000_deg,   0.0321 },
			{   -7.000_deg,   0.0079 },
			{   -5.000_deg,  -0.0055 },
			{   -4.000_deg,  -0.0041 },
			{   -3.000_deg,  -0.0035 },
			{   -2.000_deg,  -0.0004 },
			{   -1.000_deg,  -0.0010 },
			{    0.000_deg,   0.0000 },
			{    1.000_deg,   0.0010 },
			{    2.000_deg,   0.0004 },
			{    3.000_deg,   0.0035 },
			{    4.000_deg,   0.0041 },
			{    5.000_deg,   0.0055 },
			{    6.000_deg,   0.0071 },
			{   22.000_deg,  -0.1433 },
			{   23.000_deg,  -0.1524 },
			{   24.000_deg,  -0.1621 },
			{   25.000_deg,  -0.1721 },
		},
	},
};

static xf::Field<double, si::Angle, double> const
kCenterOfPressureOffsetField {
	{
		31000.0,
		{
			{  -10.000_deg,   0.3381 },
			{   -9.000_deg,   0.3439 },
			{   -8.000_deg,   0.3537 },
			{   -7.000_deg,   0.3725 },
			{   -5.000_deg,   0.2422 },
			{   -4.000_deg,   0.2373 },
			{   -3.000_deg,   0.2681 },
			{   -2.000_deg,   0.2395 },
			{   -1.000_deg,   0.2385 },
			{    0.000_deg,   0.2392 },
			{    1.000_deg,   0.2385 },
			{    2.000_deg,   0.2396 },
			{    3.000_deg,   0.2680 },
			{    4.000_deg,   0.2373 },
			{    5.000_deg,   0.2423 },
			{    6.000_deg,   0.2754 },
			{    7.000_deg,   0.3725 },
			{   11.000_deg,   0.3377 },
			{   12.000_deg,   0.3385 },
			{   18.000_deg,   0.3533 },
			{   19.000_deg,   0.3550 },
			{   20.000_deg,   0.3596 },
			{   21.000_deg,   0.3629 },
			{   22.000_deg,   0.3651 },
			{   23.000_deg,   0.3679 },
			{   24.000_deg,   0.3712 },
			{   25.000_deg,   0.3743 },
			{   26.000_deg,   0.3776 },
			{   27.000_deg,   0.3806 },
			{   28.000_deg,   0.3830 },
		},
	},
	{
		51000.0,
		{
			{  -10.000_deg,   0.3065 },
			{   -9.000_deg,   0.3173 },
			{   -8.000_deg,   0.3181 },
			{   -5.000_deg,   0.2332 },
			{   -4.000_deg,   0.2322 },
			{   -3.000_deg,   0.2425 },
			{   -2.000_deg,   0.2392 },
			{   -1.000_deg,   0.2384 },
			{    0.000_deg,   0.2385 },
			{    1.000_deg,   0.2384 },
			{    2.000_deg,   0.2393 },
			{    3.000_deg,   0.2424 },
			{    4.000_deg,   0.2322 },
			{    5.000_deg,   0.2332 },
			{   12.000_deg,   0.3279 },
			{   13.000_deg,   0.3319 },
			{   14.000_deg,   0.3378 },
			{   15.000_deg,   0.3423 },
			{   16.000_deg,   0.3439 },
			{   17.000_deg,   0.3493 },
			{   18.000_deg,   0.3539 },
			{   19.000_deg,   0.3574 },
			{   20.000_deg,   0.3610 },
			{   21.000_deg,   0.3643 },
			{   22.000_deg,   0.3676 },
			{   23.000_deg,   0.3704 },
			{   24.000_deg,   0.3726 },
			{   25.000_deg,   0.3765 },
			{   26.000_deg,   0.3792 },
			{   27.000_deg,   0.3816 },
			{   28.000_deg,   0.3846 },
			{   29.000_deg,   0.3867 },
			{   30.000_deg,   0.3896 },
		},
	},
	{
		71000.0,
		{
			{   -5.000_deg,   0.2328 },
			{   -4.000_deg,   0.2334 },
			{   -3.000_deg,   0.2383 },
			{   -2.000_deg,   0.2393 },
			{   -1.000_deg,   0.2386 },
			{    0.000_deg,   0.2383 },
			{    1.000_deg,   0.2386 },
			{    2.000_deg,   0.2393 },
			{    3.000_deg,   0.2383 },
			{    4.000_deg,   0.2334 },
			{    5.000_deg,   0.2328 },
			{    7.000_deg,   0.2945 },
			{    8.000_deg,   0.3042 },
			{   15.000_deg,   0.3403 },
			{   16.000_deg,   0.3461 },
			{   17.000_deg,   0.3508 },
			{   18.000_deg,   0.3547 },
			{   19.000_deg,   0.3580 },
			{   20.000_deg,   0.3612 },
			{   21.000_deg,   0.3638 },
			{   22.000_deg,   0.3685 },
			{   23.000_deg,   0.3714 },
			{   24.000_deg,   0.3739 },
			{   25.000_deg,   0.3774 },
		},
	},
	{
		91000.0,
		{
			{   -5.000_deg,   0.2337 },
			{   -4.000_deg,   0.2348 },
			{   -3.000_deg,   0.2373 },
			{   -2.000_deg,   0.2394 },
			{   -1.000_deg,   0.2388 },
			{    0.000_deg,   0.2381 },
			{    1.000_deg,   0.2388 },
			{    2.000_deg,   0.2394 },
			{    3.000_deg,   0.2373 },
			{    4.000_deg,   0.2348 },
			{    5.000_deg,   0.2337 },
			{   14.000_deg,   0.3379 },
			{   15.000_deg,   0.3414 },
			{   16.000_deg,   0.3445 },
			{   17.000_deg,   0.3501 },
			{   18.000_deg,   0.3552 },
			{   19.000_deg,   0.3591 },
			{   20.000_deg,   0.3625 },
		},
	},
	{
		111000.0,
		{
			{   -6.000_deg,   0.2367 },
			{   -5.000_deg,   0.2347 },
			{   -4.000_deg,   0.2361 },
			{   -3.000_deg,   0.2370 },
			{   -2.000_deg,   0.2395 },
			{   -1.000_deg,   0.2390 },
			{    0.000_deg,   0.2379 },
			{    1.000_deg,   0.2390 },
			{    2.000_deg,   0.2395 },
			{    3.000_deg,   0.2370 },
			{    4.000_deg,   0.2361 },
			{    5.000_deg,   0.2347 },
			{    9.000_deg,   0.3074 },
			{   14.000_deg,   0.3380 },
			{   15.000_deg,   0.3414 },
			{   16.000_deg,   0.3474 },
			{   17.000_deg,   0.3520 },
			{   18.000_deg,   0.3559 },
			{   19.000_deg,   0.3588 },
			{   20.000_deg,   0.3628 },
			{   21.000_deg,   0.3664 },
		},
	},
	{
		131000.0,
		{
			{   -5.000_deg,   0.2358 },
			{   -4.000_deg,   0.2371 },
			{   -3.000_deg,   0.2371 },
			{   -2.000_deg,   0.2532 },
			{   -1.000_deg,   0.2391 },
			{    0.000_deg,   0.2378 },
			{    1.000_deg,   0.2391 },
			{    2.000_deg,   0.2536 },
			{    3.000_deg,   0.2371 },
			{    4.000_deg,   0.2371 },
			{    6.000_deg,   0.2357 },
			{   14.000_deg,   0.3392 },
			{   15.000_deg,   0.3436 },
			{   16.000_deg,   0.3462 },
			{   17.000_deg,   0.3515 },
			{   18.000_deg,   0.3562 },
			{   19.000_deg,   0.3598 },
			{   20.000_deg,   0.3628 },
			{   21.000_deg,   0.3668 },
			{   23.000_deg,   0.3729 },
			{   24.000_deg,   0.3753 },
			{   25.000_deg,   0.3786 },
			{   26.000_deg,   0.3812 },
			{   27.000_deg,   0.3838 },
			{   28.000_deg,   0.3865 },
			{   29.000_deg,   0.3889 },
		},
	},
	{
		151000.0,
		{
			{   -5.000_deg,   0.2365 },
			{   -4.000_deg,   0.2379 },
			{   -3.000_deg,   0.2374 },
			{   -2.000_deg,   0.2553 },
			{   -1.000_deg,   0.2393 },
			{    0.000_deg,   0.2377 },
			{    1.000_deg,   0.2393 },
			{    2.000_deg,   0.2552 },
			{    3.000_deg,   0.2374 },
			{    4.000_deg,   0.2379 },
			{   11.000_deg,   0.3225 },
			{   12.000_deg,   0.3289 },
			{   13.000_deg,   0.3345 },
			{   14.000_deg,   0.3395 },
			{   15.000_deg,   0.3442 },
			{   16.000_deg,   0.3466 },
		},
	},
	{
		171000.0,
		{
			{   -8.000_deg,   0.2904 },
			{   -7.000_deg,   0.2587 },
			{   -5.000_deg,   0.2372 },
			{   -4.000_deg,   0.2385 },
			{   -3.000_deg,   0.2377 },
			{   -2.000_deg,   0.2471 },
			{   -1.000_deg,   0.2395 },
			{    0.000_deg,   0.2377 },
			{    1.000_deg,   0.2395 },
			{    2.000_deg,   0.2470 },
			{    3.000_deg,   0.2377 },
			{    4.000_deg,   0.2385 },
			{    5.000_deg,   0.2372 },
			{    6.000_deg,   0.2361 },
			{   22.000_deg,   0.3704 },
			{   23.000_deg,   0.3731 },
			{   24.000_deg,   0.3761 },
			{   25.000_deg,   0.3790 },
		},
	},
};

} // namespace sim_airfoil
