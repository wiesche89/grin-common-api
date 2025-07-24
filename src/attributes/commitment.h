#ifndef COMMITMENT_H
#define COMMITMENT_H

#include <QByteArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonDocument>
#include <QDebug>
#include <QMetaType>

class Commitment
{
    Q_GADGET
    // Expose the data property to Qt's meta-object system
    Q_PROPERTY(QByteArray data READ data WRITE setData)

public:
    Commitment();
    explicit Commitment(const QByteArray &data);

    // Getter
    QByteArray data() const;

    // Setter
    void setData(const QByteArray &data);

    // JSON serialization / deserialization
    void fromJson(const QJsonObject &json);
    QJsonObject toJson() const;

private:
    QByteArray m_data; // expected size: 33 bytes
};

// Register this type with Qt's meta-object system
Q_DECLARE_METATYPE(Commitment)

#endif // COMMITMENT_H
