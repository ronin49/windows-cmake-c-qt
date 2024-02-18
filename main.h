#pragma once

#include <QApplication>
#include <QGraphicsScene>
#include <QFont>
#include <QFontMetrics>
#include <QGraphicsView>
#include <QGraphicsSimpleTextItem>
#include <QFileSystemModel>
#include <QTreeView>
#include <QScreen>
#include <QAbstractTableModel>
#include <QPushButton>

#include <QAbstractItemModel>
#include <QGuiApplication>
#include <QScreen>
#include <QPixmap>
#include <QDebug>
class Model : public QAbstractItemModel {
    Q_OBJECT
public:
    Model() : image(QGuiApplication::primaryScreen()->grabWindow(0).scaled(100, 100)) {}
    QPixmap image;
    QVariant data(const QModelIndex& index, int role) const override {
        qDebug() << "lol";
        //if(index.isValid()==0||role!=Qt::DisplayRole) return QVariant();
        if (index.isValid() && role == Qt::DecorationRole)
        {
        }
        else return {};
        QPixmap p(200, 200);
        p.fill(Qt::black);
        //return p;
        return image;
        //return QGuiApplication::primaryScreen()->grabWindow(0).scaled(100,100);
    }
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override { return QString("lol"); }
    QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override {

        return createIndex(row, column);
    }
    QModelIndex parent(const QModelIndex& index) const override { return QModelIndex(); }
    int rowCount(const QModelIndex& parent = QModelIndex()) const override {
        auto p = QModelIndex();
        //beginInsertRows(p,0,1);
        //endInsertRows();
        //endInsertRows();
        //endInsertRows();
        return i;
    }
    int columnCount(const QModelIndex& parent = QModelIndex()) const override { return 3; }
    //bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) {
    //    return 0;
    //}
    int i = 0;
    void f() {
        beginInsertRows(QModelIndex(), 0, 0);
        i++;
        endInsertRows();
    }
};

namespace Game::Graphics::Physics {

    int i;
}

int main(int argc, char* argv[]) {
    auto lol = 2;
    QApplication a(argc, argv);
    Model* model = new Model;
    //model->setRootPath(QDir::currentPath());
    QTreeView tree;
    QPushButton b(&tree);
    tree.setItemsExpandable(false);
    tree.setModel(model);
    tree.show();
    model->f();
    qDebug() << 2;
    return a.exec();
}
