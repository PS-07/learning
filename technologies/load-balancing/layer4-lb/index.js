const app = require("express")()
const port = process.env.PORT || 3000

app.get("/*", (req, res) => {
    res.send(`served by ${port}`)
})

app.listen(port, () => console.log(`listening on port: ${port}`))