#include "launcher/launcher.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

namespace Gui::Launcher {
    int start(int argc, char **argv) {
        QGuiApplication app(argc, argv);
        QQmlApplicationEngine engine;

        QObject::connect(
            &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
            []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
        engine.loadFromModule("gui.launcher", "Main");

        return QGuiApplication::exec();
    }
} // namespace Gui::Launcher
