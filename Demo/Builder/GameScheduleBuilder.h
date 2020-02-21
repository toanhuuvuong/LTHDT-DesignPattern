#ifndef __GAME_SCHEDULE_BUILDER_H__
#define __GAME_SCHEDULE_BUILDER_H__

#include<iostream>
#include<vector>
#include<iomanip>
#include<string>

// Product
class GAME
{
private:
	std::string m_time, m_homeTeam, m_awayTeam;
public:
	GAME() {}
	GAME(const std::string &time, const std::string &homeTeam, const std::string &awayTeam) : m_time(time), m_homeTeam(homeTeam), m_awayTeam(awayTeam) {}

	void setTime(const std::string &time) { m_time = time; }
	void setHomeTeam(const std::string &homeTeam) { m_homeTeam = homeTeam; }
	void setAwayTeam(const std::string &awayTeam) { m_awayTeam = awayTeam; }

	std::string getTime() const { return m_time; }
	std::string getHomeTeam() const { return m_homeTeam; }
	std::string getAwayTeam() const { return m_awayTeam; }

	void display()
	{
		std::cout << std::setw(8) << std::left << m_time;
		std::cout << std::setw(30) << std::left << m_homeTeam;
		std::cout << std::setw(30) << std::left << m_awayTeam << std::endl;
	}
};
class GAME_DATE
{
private:
	std::string m_date;
public:
	std::vector<GAME*> m_listGame;

	GAME_DATE() {}
	GAME_DATE(const std::string &date) : m_date(date) {}

	void setDate(const std::string &date) { m_date = date; }
	void addGame(GAME* newGame)
	{
		m_listGame.push_back(newGame);
	}

	std::string getDate() const { return m_date; }

	void display()
	{
		int size = m_listGame.size();
		std::cout << std::setw(16) << std::left << m_date << std::endl;

		for (int i = 0; i < size; i++)
		{
			std::cout << "\t";
			m_listGame[i]->display();
		}
	}
};
class GAME_SCHEDULE
{
public:
	std::vector<GAME_DATE*> m_listGameDate;

	GAME_SCHEDULE(const std::string &gameType) { std::cout << gameType << std::endl; }

	void addGameDate(GAME_DATE* newGameDate)
	{
		m_listGameDate.push_back(newGameDate);
	}

	void display()
	{
		int size = m_listGameDate.size();
		for (int i = 0; i < size; i++)
		{
			m_listGameDate[i]->display();
			std::cout << std::endl;
		}
	}
};
// Builder
class GAME_SCHEDULE_BUILDER
{
protected:
	GAME_SCHEDULE* m_result;
public:
	virtual void buildDate(const std::string &date) = 0;
	virtual void buildGame(const std::string &date, GAME* newGame) = 0;

	GAME_SCHEDULE* getResult() const { return m_result; }
};
class SPORT_GAME_SCHEDULE_BUILDER : public GAME_SCHEDULE_BUILDER
{
public:
	SPORT_GAME_SCHEDULE_BUILDER(){ m_result = new GAME_SCHEDULE("SPORT"); }

	virtual void buildDate(const std::string &date)
	{
		int size = m_result->m_listGameDate.size();
		while (size--)
		{
			if (m_result->m_listGameDate[size]->getDate() == date)
				return;
		}
		m_result->addGameDate(new GAME_DATE(date));
	}
	virtual void buildGame(const std::string &date, GAME* newGame)
	{
		int size = m_result->m_listGameDate.size();
		while (size--)
		{
			if (m_result->m_listGameDate[size]->getDate() == date)
			{
				m_result->m_listGameDate[size]->addGame(newGame);
				return;
			}
		}
	}
};
// Director
class DIRECTOR
{
private:
	GAME_SCHEDULE_BUILDER* m_builder;
public:
	void setBuilder(GAME_SCHEDULE_BUILDER* builder) { m_builder = builder; }
	void construct()
	{
		m_builder->buildDate("09/07/2017");
		m_builder->buildGame("09/07/2017", new GAME("8:30pm", "Kansas City Chiefs", "New England Patriots"));

		m_builder->buildDate("09/10/2017");
		m_builder->buildGame("09/10/2017", new GAME("1:00pm", "Buffalo Bills", "New York Jets"));
		m_builder->buildGame("09/10/2017", new GAME("1:00pm", "Philadelphia Eagles", "Washington Redskins"));
		m_builder->buildGame("09/10/2017", new GAME("1:00pm", "Las Vegas Raiders", "Tennessee Titans"));
		m_builder->buildGame("09/10/2017", new GAME("1:00pm", "Tampa Bay Buccaneers", "Miami Dolphins"));
		m_builder->buildGame("09/10/2017", new GAME("4:05pm", "Indianapolis Colts", "Los Angeles Rams"));
		m_builder->buildGame("09/10/2017", new GAME("8:30pm", "New York Giants", "Dallas Cowboys"));

		m_builder->buildDate("09/11/2017");
		m_builder->buildGame("09/11/2017", new GAME("7:10pm", "New Orleans Saints", "Minnesota Vikings"));
		m_builder->buildGame("09/11/2017", new GAME("10:20pm", "San Diego Chargers", "Denver Broncos"));
	}
};

#endif
