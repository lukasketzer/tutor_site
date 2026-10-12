import { guideMarkdown } from "$lib/ssh/guide.js";

export const prerender = true;

// Markdown version of the SSH guide, linked from /llms.txt. Not named ssh.md:
// Apache MultiViews on the host would then treat it as a variant of /ssh.
export function GET() {
    return new Response(guideMarkdown, {
        headers: { "content-type": "text/markdown; charset=utf-8" },
    });
}
