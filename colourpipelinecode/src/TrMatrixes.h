namespace TrMatrixes
{
	constexpr float sRgb[9] = { 0.4124564,  0.3575761,  0.1804375,
								0.2126729,  0.7151522,  0.0721750,
								0.0193339,  0.1191920,  0.9503041 };

	constexpr float adobeRgb[9] = { 0.5767309,  0.1855540,  0.1881852,
									0.2973769,  0.6273491,  0.0752741,
								    0.0270343,  0.0706872,  0.9911085 };

	constexpr float appleRgb[9] = { 0.4497288,  0.3162486,  0.1844926,
									0.2446525,  0.6720283,  0.0833192,
								    0.0251848,  0.1411824,  0.9224628 };

	constexpr float bestRgb[9] = { 0.6326696,  0.2045558,  0.1269946,
								   0.2284569,  0.7373523,  0.0341908,
								   0.0000000,  0.0095142,  0.8156958 };

	constexpr float betaRgb[9] = { 0.6712537,  0.1745834,  0.1183829,
								   0.3032726,  0.6637861,  0.0329413,
								   0.0000000,  0.0407010,  0.7845090 };

	constexpr float colorMatchRgb[9] = { 0.5093439,  0.3209071,  0.1339691,
										 0.2748840,  0.6581315,  0.0669845,
										 0.0242545,  0.1087821,  0.6921735 };

	constexpr float ektaSpaceRgb[9] = { 0.5938914,  0.2729801,  0.0973485,
										0.2606286,  0.7349465,  0.0044249,
										0.0000000,  0.0419969,  0.7832131 };

	constexpr float palSecamRgb[9] = { 0.4306190,  0.3415419,  0.1783091,
									   0.2220379,  0.7066384,  0.0713236,
									   0.0201853,  0.1295504,  0.9390944 };

	constexpr float smpte_cRgb[9] = { 0.3935891,  0.3652497,  0.1916313,
									  0.2124132,  0.7010437,  0.0865432,
									  0.0187423,  0.1119313,  0.9581563 };
}