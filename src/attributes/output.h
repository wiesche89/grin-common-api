#ifndef OUTPUT_H
#define OUTPUT_H

#include <QString>
#include <QJsonObject>
#include <QMetaType>

class Output
{
    Q_GADGET
    // Expose properties to Qt's meta-object system
    Q_PROPERTY(QString commit READ commit WRITE setCommit)
    Q_PROPERTY(QString features READ features WRITE setFeatures)
    Q_PROPERTY(QString proof READ proof WRITE setProof)

public:
    Output();
    Output(const QString &commit, const QString &features, const QString &proof);

    // JSON serialization / deserialization
    QJsonObject toJson() const;
    static Output fromJson(const QJsonObject &obj);

    // Getters
    QString commit() const;
    QString features() const;
    QString proof() const;

    // Setters
    void setCommit(const QString &commit);
    void setFeatures(const QString &features);
    void setProof(const QString &proof);

private:
    QString m_commit;
    QString m_features;
    QString m_proof;
};

// Register this type with Qt's meta-object system
Q_DECLARE_METATYPE(Output)

#endif // OUTPUT_H
