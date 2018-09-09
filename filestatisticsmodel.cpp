#include "filestatisticsmodel.h"

FileStatisticsModel::FileStatisticsModel()
{

}

uint32_t FileStatisticsModel::getFilesCount() const
{
    return filesCount;
}

double FileStatisticsModel::getAllSize() const
{
    return allSize;
}

void FileStatisticsModel::setModel(const FileStatisticsModel &newModel)
{
    filesCount = newModel.getFilesCount();
    allSize = newModel.getAllSize();
    emit modelChanged(*this);
}

void FileStatisticsModel::clean()
{
    filesCount = 0;
    allSize = 0;
    avgSizePerExt.clear();
}

void FileStatisticsModel::updateModel(QFileInfo file)
{
    //update files count
    filesCount++;
    auto size = file.size();
    //update files size
    allSize += size;
    auto extension = file.completeSuffix();
    //update avarage by extension
    if(avgSizePerExt.contains(extension))
    {
        //inc samples count
        avgSizePerExt[extension].second ++;
        //eval cumulative moving average
        avgSizePerExt[extension].first =
                avgSizePerExt[extension].first +
                (double)(size-avgSizePerExt[extension].first)/
                avgSizePerExt[extension].second;
    }
    else
    {
        avgSizePerExt.insert(extension, SumAndCount(size, 1));
    }
    emit modelChanged(*this);
}
