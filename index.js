const fs = require("fs")
var htmlLines = []
fs.readFile("src/index.html", (error, data) => {
  if (error) { throw error; }
  
  data.toString().split("\n").forEach((line, index, arr) => {
    htmlLines.push(line.replace(/\r?\n|\r/g, "").replace(/"/g,'\\"'))    
    if (index === arr.length - 1 && line === "") {
      fs.writeFile("src/html.ino", getHtmlTemplate(htmlLines), (error) => { if (error) { throw error; } })
    }
  })
})


function getHtmlTemplate(htmlLines)
{
  const htmlTemplate = `
String getHtml() 
{
  String html = "";
${htmlLines.map(l => "  html += \"" + l + "\";").join("\n")}
  return html;
}
  `
  return htmlTemplate
}