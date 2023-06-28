# MOC Bug

This project replicates the bug in https://bugreports.qt.io/browse/QTBUG-60539 . Uncomment the `DEFINES += ENABLE_BUG` line in the [project file](moc_bug_lambda_slot_param.pro) and rebuild to check if the MOC generates code that moves a `const` from the signature of a `std::function` to the wrong position.

