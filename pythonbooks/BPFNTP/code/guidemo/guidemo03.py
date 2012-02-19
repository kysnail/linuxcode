#/usr/bin/python
#encoding=utf-8

import wx

app = wx.App()
win = win.Frame(None, title="Simple Editor")

loadButton = wx.Button(win, label='Open')
saveButton = wx.Button(win, label='Save')

win.Show()

app.MainLoop()

