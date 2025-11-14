#ifndef RESULT_H
#define RESULT_H

#include <QDebug>
#include "error.h"

template<typename T>
class Result
{
public:

    Result()
        : m_value()
        , m_error()
        , m_hasError(false)
    {
    }

    /**
     * @brief Statische Hilfsmethoden für kompaktere Nutzung
     */
    static Result<T> ok(const T &value)
    {
        return Result<T>(value);
    }

    bool ok() const
    {
        return !m_hasError;
    }

    static Result<T> error(const QString &message)
    {
        Error e;
        e.message = message;
        return Result<T>(e);
    }

    static Result<T> error(const Error &err)
    {
        return Result<T>(err);
    }

    /**
     * @brief Result mit Wert
     */
    Result(const T &value) :
        m_value(value),
        m_hasError(false)
    {
    }

    /**
     * @brief Result mit Fehler
     */
    Result(const Error &error) :
        m_error(error),
        m_hasError(true)
    {
    }

    /**
     * @brief Gibt true zurück, wenn ein Fehler vorhanden ist.
     */
    bool hasError() const
    {
        return m_hasError;
    }

    /**
     * @brief Gibt den Fehler zurück.
     */
    Error error() const
    {
        return m_error;
    }

    /**
     * @brief Gibt den Wert zurück.
     */
    T value() const
    {
        return m_value;
    }

    /**
     * @brief Gibt den Wert aus oder loggt den Fehler.
     */
    bool unwrapOrLog(T &out) const
    {
        if (m_hasError) {
            qDebug() << "Error:" << m_error.message;
            return false;
        }
        out = m_value;
        return true;
    }

    /**
     * @brief Gibt die Fehlermeldung als QString zurück.
     */
    QString errorMessage() const
    {
        return m_hasError ? m_error.message : QString();
    }

private:
    T m_value{};
    Error m_error;
    bool m_hasError{false};
};

#endif // RESULT_H
