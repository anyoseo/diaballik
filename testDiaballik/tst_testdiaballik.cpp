#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class TestDiaballik : public QObject
{
    Q_OBJECT

public:
    TestDiaballik();
    ~TestDiaballik();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

TestDiaballik::TestDiaballik()
{

}

TestDiaballik::~TestDiaballik()
{

}

void TestDiaballik::initTestCase()
{

}

void TestDiaballik::cleanupTestCase()
{

}

void TestDiaballik::test_case1()
{

}

QTEST_MAIN(TestDiaballik)

#include "tst_testdiaballik.moc"
