#!/bin/bash

rm release/*
rm build/debug/*
rm build/debug/.moc/*
rm build/debug/.obj/*
rm build/release/*
rm build/release/.moc/*
rm build/release/.obj/*
rm src/qt/locale/*.qm

rm Makefile
rm Makefile.Debug
rm Makefile.Release
rm b2block_plugin_import.cpp
rm b2block_resource.rc