#include "statistics.hh"
#include <QString>
#include <QtTest>
#include <memory>

class StatisticsTest : public QObject
{
    Q_OBJECT

public:
    StatisticsTest();

private Q_SLOTS:
    void init();
};

StatisticsTest::StatisticsTest() {
}


void StatisticsTest::init() {
}

QTEST_APPLESS_MAIN(StatisticsTest)

#include "statisticstest.moc"
