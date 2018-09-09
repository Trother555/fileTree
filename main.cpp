#include "mainwindow.h"
#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QDir>
#include "filestatisticscontroller.h"
#include "filestatisticsviewcontainer.h"
#include <QModelIndex>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //set up the fileTree with a model
    QFileSystemModel fsModel;
    fsModel.setRootPath("C:/Users/Pavel/Desktop/asd");
    auto fileTree = w.findChild<QTreeView*>("fileTree");
    fileTree->setModel(&fsModel);
    fileTree->setAnimated(false);
    fileTree->setIndentation(20);
    fileTree->setSortingEnabled(true);
    const QModelIndex rootIndex = fsModel.
            index(QDir::cleanPath("C:/Users/Pavel/Desktop/asd"));
    fileTree->setRootIndex(rootIndex);

    //set up slots for statistics controller
    FileStatisticsController controller(&a);

    //set up the statistics constorrelr with model
    FileStatisticsModel statisticsModel;
    controller.setModel(&statisticsModel);

    //set up the statistics view
    FileStatisticsViewContainer statisticsView;
    statisticsView.setFileCountView(w.findChild<QLabel*>("fileCount"));
    statisticsView.setAllSizeView(w.findChild<QLabel*>("allSize"));

    //connecting signals to slots
    QObject::connect(fileTree, &QTreeView::activated,
                     &controller, &FileStatisticsController::updateStatistics);
    QObject::connect(&statisticsModel, &FileStatisticsModel::modelChanged,
                     &statisticsView, &FileStatisticsViewContainer::updateView);

    return a.exec();
}
