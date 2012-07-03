Sub ReplaceBrace()
'
'
	Set objWord = CreateObject("Word.Application")
	objWord.Visible = True

	' 这里文件地址可以替换为你需要的路径
	Set objDoc = objWord.Documents.Open("C:\Users\kangyushi.XAUSE\Desktop\01.doc")
	Set objSelection = objWord.Selection

	' 使用 MatchWildCard 方式进行查找
	With objSelection.Find
	    .ClearFormatting
	    .Text = "\(σ\)[0-9a-zA-Z]{1,}"
	    .MatchAllWordForms = False
	    .MatchSoundsLike = False
	    .MatchFuzzy = False
	    .MatchWildcards = True
	    .Replacement.Text = "(σ)__"
	End With
	 
	objSelection.Find.Execute , , , , , , , , , , wdReplaceAll

End Sub
 



