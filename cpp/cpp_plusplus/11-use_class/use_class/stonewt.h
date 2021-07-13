#pragma once
class Stonewt
{
public:
	Stonewt(double lbs);//Constructor for double pounds.
	Stonewt(int stn, double lbs);//Constructor for stone,lbs.
	Stonewt();//Default constructor.
	~Stonewt();

	int Init();
	int Uninit();
	void ShowLbs()const;//Show weight in pounds format;
	void ShowStn()const;//Show weight in stone format;

private:
	enum class LbsPerStn
	{
		LBS_PER_STN = 14,//Pounds per stone. 
	};
	int m_stone;//Whole stones.
	double m_pds_left; //fractional pounds.
	double m_pounds;//entire weight in pounds.
	int m_init_success;
};

